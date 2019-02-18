type wsApp;
type ws;

module CloseEvent = CloseEvent;
module ErrorEvent: { type t; };
module MessageEvent: { type t = string; };

let make: Express.App.t => wsApp;
let listen: (wsApp, string, (ws, Express.Request.t) => unit) => unit;
let onError: (ws, ErrorEvent.t => unit) => unit;
let onMessage: (ws, MessageEvent.t => unit) => unit;
let onClose: (ws, CloseEvent.t => unit) => unit;
