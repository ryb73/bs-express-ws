let app = Express.App.make();
let wsApp = ExpressWs.make(app);

ExpressWs.listen(wsApp, "/", (ws, _) => {
    ExpressWs.onClose(ws, Js.log2("Close"));
    ExpressWs.onMessage(ws, Js.log2("Message"));
    ExpressWs.onError(ws, Js.log2("Error"));
});

Express.App.listen(app, ~port=3000, ());
