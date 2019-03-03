type wsApp;
type ws;

module CloseEvent = CloseEvent;
module ErrorEvent = { type t; };
module MessageEvent = { type t = string; };

external fromApp: Express.App.t => wsApp = "%identity";

[@bs.module]
external apply:
    Express.App.t => (~server: Express.HttpServer.t=?) => unit = "express-ws";

let make = (~server=?, app) => {
    apply(app, ~server?);
    fromApp(app);
};

[@bs.send]
external listen: wsApp => string => (ws => Express.Request.t => unit) => unit = "ws";

[@bs.send]
external onError: ws => ([@bs.as "error"] _) => (ErrorEvent.t => unit) => unit = "on";
[@bs.send]
external onMessage: ws => ([@bs.as "message"] _) => (MessageEvent.t => unit) => unit = "on";

[@bs.send]
external onClose: ws => ([@bs.as "close"] _) => (Js.Json.t => unit) => unit = "on";
let onClose = (ws, cb) => onClose(ws, json => cb(CloseEvent.t_decode(json)));

[@bs.send] external send: ws => string => unit = "";
