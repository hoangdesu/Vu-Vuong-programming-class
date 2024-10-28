import io.javalin.Javalin;

public class HelloJavalin {
    public static void main(String[] args) {
        var app = Javalin.create(/*config*/)
                .get("/", ctx -> ctx.result("Hello World"))
                .get("/hi", ctx -> ctx.result("Wassupppp"))
                .get("/hi/{name}", ctx -> {
                    String name = ctx.pathParam("name");
                    ctx.html("<h1>Wassuppppp " + name + "</h1>");
                })
                .start(7071);
    }
}