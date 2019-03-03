let app = Express.App.make();

let server = Express.App.listen(app, ~port=3001, ());

let wsApp = ExpressWs.make(~server, app);

ExpressWs.listen(wsApp, "/ws", (ws, _) => {
    ExpressWs.onClose(ws, Js.log2("Close"));
    ExpressWs.onMessage(ws, m => {
        Js.log2("Message", m);
        ExpressWs.send(ws, m);
    });
    ExpressWs.onError(ws, Js.log2("Error"));
});
