'use strict';

var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var FetchExample$ReasonReactExample = require("./FetchExample.bs.js");

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, FetchExample$ReasonReactExample.make(/* array */[])), "index");

/*  Not a pure module */
