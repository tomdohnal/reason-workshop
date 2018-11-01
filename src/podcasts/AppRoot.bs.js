'use strict';

var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ApolloProvider = require("reason-apollo/src/ApolloProvider.bs.js");
var Client$ReasonReactExample = require("./Client.bs.js");
var JustApp$ReasonReactExample = require("./JustApp.bs.js");

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, ApolloProvider.make(Client$ReasonReactExample.instance, /* array */[ReasonReact.element(undefined, undefined, JustApp$ReasonReactExample.make(/* array */[]))])), "index");

/*  Not a pure module */
