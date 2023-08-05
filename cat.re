open Tyxml

[@deriving yojson]
type something = {
  files: array(string)
};

let generate_response =
  something_to_yojson({ files: Sys.readdir(".") })
  |> Yojson.Safe.to_string

let amogus =
  <div>
    <div>{Html.txt("boom")}</div>
    <button _hx_get="/cat" _hx_swap="innerHtml">"Click Me"</button>
  </div>

let greet = _ =>
  <html>
    <head>
      <title>"Home"</title>
      <script src="https://unpkg.com/htmx.org@1.9.4"></script>
    </head>
    <body>
      {amogus}
    </body>
  </html>

let html_to_string = html =>
  Format.asprintf("%a", Tyxml.Html.pp(), html);

let () =
  Dream.run
  @@ Dream.logger
  @@ Dream.router([

    Dream.get("/",
      (_ => Dream.html(html_to_string(greet("world"))))),

    Dream.get("/cat",
    (_ => Dream.json(generate_response)))
  ]);