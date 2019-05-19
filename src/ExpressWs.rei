type wsApp;
type ws;

module CloseEvent: { type t; };
module ErrorEvent: { type t; };
module MessageEvent: { type t = string; };

let make: (~server: Express.HttpServer.t=?, Express.App.t) => wsApp;
let listen: (wsApp, string, (ws, Express.Request.t) => unit) => unit;
let onError: (ws, ErrorEvent.t => unit) => unit;
let onMessage: (ws, MessageEvent.t => unit) => unit;
let onClose: (ws, CloseEvent.t => unit) => unit;
let send: (ws, string) => unit;
