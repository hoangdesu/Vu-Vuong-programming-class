package app;

import io.javalin.Javalin;
import io.javalin.core.util.RouteOverviewPlugin;
import java.util.HashMap;

/**
 * Main Application Class.
 * <p>
 * Running this class as regular java application will start the
 * Javalin HTTP Server and our web application.
 *
 * @author Timothy Wiley, 2023. email: timothy.wiley@rmit.edu.au
 * @author Santha Sumanasekara, 2021. email: santha.sumanasekara@rmit.edu.au
 * @author Halil Ali, 2024. email: halil.ali@rmit.edu.au
 */

public class App {

  public static final int JAVALIN_PORT = 7001;
  public static final String CSS_DIR = "css/";
  public static final String IMAGES_DIR = "images/";

  public static void main(String[] args) {
    // Create our HTTP server and listen in port 7001
    Javalin app = Javalin
      .create(config -> {
        config.registerPlugin(new RouteOverviewPlugin("/help/routes"));

        // Uncomment this if you have files in the CSS Directory
        config.addStaticFiles(CSS_DIR);

        // Uncomment this if you have files in the Images Directory
        config.addStaticFiles(IMAGES_DIR);

        config.addStaticFiles("javascripts/");
      })
      .start(JAVALIN_PORT);

    // Configure Web Routes
    configureRoutes(app);
  }

  public static void configureRoutes(Javalin app) {
    // All webpages are listed here as GET pages
    app.get(PageIndex.URL, new PageIndex()); // "/"
    app.get(PageMission.URL, new PageMission()); // "/mission.html"
    app.get(PageST2A.URL, new PageST2A());
    app.get(PageST2B.URL, new PageST2B());
    app.get(PageST3A.URL, new PageST3A());
    app.get(PageST3B.URL, new PageST3B());

    app.post(
      "/filter-data",
      context -> {
        JDBCConnection jdbcConnection = new JDBCConnection();

        String area = context.formParam("area");
        String fromYear = context.formParam("fromYear");
        String toYear = context.formParam("toYear");

        System.out.println("--- server");
        System.out.println("from to years: " + fromYear + " " + toYear);

        double[] differences = jdbcConnection.getRegionalOrganicCollectedWasteDifference(
          fromYear,
          toYear
        );

        System.out.println("> diff: " + differences[0]);

        HashMap<String, Object> data = new HashMap<>();

        // put data here
        data.put("difference", String.format("%.2f", differences[0]));
        data.put("diffPercentage", String.format("%.2f%%", differences[1]) );

        context.render("IdentifyChanges.html", data);
      }
    );
    // uncomment the following for groups of 3
    // you will need to copy and create the relevant class file from the corresponding template above
    // app.get(PageSummary.URL, new PageSummary());
    // app.get(PageST2C.URL, new PageST2C());
    // app.get(PageST3C.URL, new PageST3C());

    // Add / uncomment POST commands for any pages that need web form POSTS
    // app.post(PageIndex.URL, new PageIndex());
    // app.post(PageMission.URL, new PageMission());
    // app.post(PageST2A.URL, new PageST2A());
    // app.post(PageST2B.URL, new PageST2B());
    // app.post(PageST3A.URL, new PageST3A());
    // app.post(PageST3B.URL, new PageST3B());

    // uncomment the following for groups of 3 - for any pages that need a web form POSTS
    // app.post(PageSummary.URL, new PageSummary());
    // app.post(PageST2C.URL, new PageST2C());
    // app.post(PageST3C.URL, new PageST3C());
  }
}
