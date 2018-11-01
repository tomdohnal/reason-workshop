/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache(());

/* Create an HTTP Link */
let httpLink =
 ApolloLinks.createHttpLink(~uri="https://serve.onegraph.com/dynamic?app_id=0b33e830-7cde-4b90-ad7e-2a39c57c0e11", ());

let instance = ReasonApollo.createApolloClient(
 ~link=httpLink, 
 ~cache=inMemoryCache, 
 ()
);
