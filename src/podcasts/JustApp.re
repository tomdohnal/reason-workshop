type state = {currentPodcastTitle: string};

type action =
  | Click(string);

let component = ReasonReact.reducerComponent("JustApp");

/* Create a GraphQL Query by using the graphql_ppx */
module GetPodcasts = [%graphql
  {|
  query getFeed {
    rss {
      rss2Feed(url: "http://podcasts.files.bbci.co.uk/p02pc9pj.rss") {
        items {
          source {
            data
            url
          }
          enclosure {
            url
            length
            mime
          }
          content
          pubDate
          contentUri
          comments
          link
          author
          title
          guid {
            data
          }
        }
        title
        image {
          height
          title
          uri
          width
          description
        }
      }
    }
  }
|}
];

module GetPodcastsQuery = ReasonApollo.CreateQuery(GetPodcasts);

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element (Page.make message::"hello" [||])` */


let make = (_children) => {
  ...component,
  initialState: () => {currentPodcastTitle: ""},
  reducer: (action, _) =>
    switch (action) {
    | Click(newTitle) => ReasonReact.Update({currentPodcastTitle: newTitle})
    },
  render: self =>
    <GetPodcastsQuery>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => <div> {ReasonReact.string("Loading")} </div>
             | Error(error) =>
               <div> {ReasonReact.string(error##message)} </div>
             | Data(response) =>
               <div>
                 <h1>
                   {ReasonReact.string(response##rss##rss2Feed##title)}
                 </h1>
                 {
                   switch (response##rss##rss2Feed##image) {
                   | None => ReasonReact.null
                   | Some(image) =>
                     <img
                       src=image##uri
                       width={string_of_int(image##width)}
                       height={string_of_int(image##height)}
                     />
                   }
                 }
                 {
                   if (self.state.currentPodcastTitle != "") {
                     <h2>
                       {
                         ReasonReact.string(
                           "Current podcast: "
                           ++ self.state.currentPodcastTitle,
                         )
                       }
                     </h2>;
                   } else {
                     ReasonReact.null;
                   }
                 }
                 {
                   ReasonReact.array(
                     response##rss##rss2Feed##items
                     ->Belt.Array.keepMap(item =>
                         switch (item##enclosure) {
                         | Some(enc) =>
                           Some(
                             <marquee key=enc##url>
                               <div>
                                 <h3
                                   style=ReactDOMRe.Style.(
                                     make(~background="pink", ~color="white", ~padding="1rem", ())
                                   )>
                                   {ReasonReact.string(item##title)}
                                 </h3>
                                 <audio
                                   controls=true
                                   src=enc##url
                                   onClick=(
                                     _event => self.send(Click(item##title))
                                   )
                                 />
                               </div>
                             </marquee>,
                           )
                         | None => None
                         }
                       ),
                   )
                 }
               </div>
             }
         }
    </GetPodcastsQuery>,
};
