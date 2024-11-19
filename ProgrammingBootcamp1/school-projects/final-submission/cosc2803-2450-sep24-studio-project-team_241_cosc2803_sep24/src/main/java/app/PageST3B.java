package app;

import io.javalin.http.Context;
import io.javalin.http.Handler;

/**
 * Example Index HTML class using Javalin
 * <p>
 * Generate a static HTML page using Javalin
 * by writing the raw HTML into a Java String object
 *
 * @author Timothy Wiley, 2023. email: timothy.wiley@rmit.edu.au
 * @author Santha Sumanasekara, 2021. email: santha.sumanasekara@rmit.edu.au
 * @author Halil Ali, 2024. email: halil.ali@rmit.edu.au
 */

public class PageST3B implements Handler {

    // URL of this page relative to http://localhost:7001/
    public static final String URL = "/page3B.html";

    @Override
    public void handle(Context context) throws Exception {
        // JDBCConnection jdbcConnection = new JDBCConnection();
        // String area = context.formParam("area");
        // String fromYear = context.formParam("fromYear");
        // String toYear = context.formParam("toYear");

        // System.out.println("--- server");
        // System.out.println("area:" + area);
        // System.out.println("from to years: " + fromYear + " " + toYear);

        // double difference[] = jdbcConnection.getRegionalOrganicCollectedWasteDifference("SMA", "2016", "2019");

        // HashMap<String, Object> data = new HashMap<>();

        // // put data here
        // data.put("differenceValue", difference[0]);
        // data.put("diffPercentage", difference[1]);
        // data.put("recycledDifference", difference[2]);
        // data.put("recycledPercentage", difference[3]);

        context.render("IdentifyChanges.html");
    }

}