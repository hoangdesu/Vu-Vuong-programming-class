package app;

import io.javalin.Javalin;
import io.javalin.core.util.RouteOverviewPlugin;
import io.javalin.http.Context;


/**
 * Main Application Class.
 * <p>
 * Running this class as regular java application will start the 
 * Javalin HTTP Server and our web application.
 *
 * @author Timothy Wiley, 2023. email: timothy.wiley@rmit.edu.au
 * @author Santha Sumanasekara, 2021. email: santha.sumanasekara@rmit.edu.au
 */
public class App {

    public static final int         JAVALIN_PORT    = 7001;
    public static final String      CSS_DIR         = "css/";
    public static final String      IMAGES_DIR      = "images/";

    public static final String[] food = {"pho", "com tam", "bun dau mam tom"};

    public static void main(String[] args) {
        // Create our HTTP server and listen in port 7001
        Javalin app = Javalin.create(config -> {
            config.registerPlugin(new RouteOverviewPlugin("/help/routes"));
            
            // Uncomment this if you have files in the CSS Directory
            config.addStaticFiles(CSS_DIR);

            // Uncomment this if you have files in the Images Directory
            config.addStaticFiles(IMAGES_DIR);
        }).start(JAVALIN_PORT);


        // Configure Web Routes
        configureRoutes(app);

        // app.get("/about", ctx -> {
        //     String template = """
        //             <h1>About me</h1>
        //             <p>My name is <b>Vuong</b><p>
        //             """;
            
        //             ctx.html(template);
        // });
        
    }

    public static void configureRoutes(Javalin app) {
        // ADD ALL OF YOUR WEBPAGES HERE
        app.get(PageIndex.URL, new PageIndex()); // app.get("/")
        app.get(PageIndex2.URL, new PageIndex2());
    
        app.get("/about", ctx -> {
            String template = """
            <h1>About me</h1>
            <p>My name is <b>Vuong</b><p>
            """;
    
            ctx.html(template);
        });


        app.get("/hello", ctx -> {
            ctx.json(food);
        });


        app.get("/food", ctx -> {
            String template = """
                    <h1 style="color: green;">Top food:</h1>
                    <ol>
                    """;

            for (String name : food) {
                String item = "<li style=\"color: red;\">" + name + "</li>";
                template += item;
            }

            template += "</ol>";

            ctx.html(template);
        });
    }

}
