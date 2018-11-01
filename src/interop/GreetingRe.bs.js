'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var MyBannerRe$ReasonReactExample = require("./MyBannerRe.bs.js");

var component = ReasonReact.statelessComponent("PageReason");

function make(message, extraGreeting, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              var greeting = extraGreeting !== undefined ? extraGreeting : "How are you?";
              return React.createElement("div", undefined, ReasonReact.element(undefined, undefined, MyBannerRe$ReasonReactExample.make(true, message + (" " + greeting), /* array */[])));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var jsComponent = ReasonReact.wrapReasonForJs(component, (function (jsProps) {
        return make(jsProps.message, Js_primitive.nullable_to_opt(jsProps.extraGreeting), jsProps.children);
      }));

exports.component = component;
exports.make = make;
exports.jsComponent = jsComponent;
/* component Not a pure module */
