package app;

import java.util.HashMap;

import io.javalin.http.Context;
import io.javalin.http.Handler;

public class FilterDataPageST3BHandler implements Handler {
    // URL of this page relative to http://localhost:7001/
    public static final String URL = "/page3B.html";

    @Override
    public void handle(Context context) throws Exception {
        JDBCConnection jdbcConnection = new JDBCConnection();

            String area = context.formParam("area");
            String fromYear = context.formParam("fromYear");
            String toYear = context.formParam("toYear");

            System.out.println("--- server");
            System.out.println("from to years: " + fromYear + " " + toYear);

            HashMap<String, Object> data = jdbcConnection.getRegionalOrganicCollectedWasteDifference(
                        area,
                        fromYear,
                        toYear
                    );

            // System.out.println("> diff: " + dbData);

            // HashMap<String, Object> data = new HashMap<>();

            // put data here
            // data.put("difference", String.format("%.2f", differences[0]));
            // data.put("diffPercentage", String.format("%.2f%%", differences[1]));
            // data.put("recycledDifference", String.format("%.2f", differences[2]));
            // data.put("recycledPercentage", String.format("%.2f%%", differences[3]));

            context.render("IdentifyChanges.html", data);
    }

}