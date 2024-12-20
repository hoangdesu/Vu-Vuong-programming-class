package app;

import java.util.ArrayList;
import java.util.HashMap;

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

public class PageST2B implements Handler {

    // URL of this page relative to http://localhost:7001/
    public static final String URL = "/page2B.html";

    @Override
    public void handle(Context context) throws Exception {
        // String queryString = context.queryString();
        
        // System.out.println(">> queryString: " + queryString); // regional-group=Rest+of+NSW&waste-resource-type=waste

        String regionalGroup = context.queryParam("regional-group");
        String wasteResourceType = context.queryParam("waste-resource-type");

        System.out.println("regionalGroup: " + regionalGroup);
        System.out.println("wasteResourceType: " + wasteResourceType);

        JDBCConnection jdbc = new JDBCConnection();

        ArrayList<LGA> lgas = jdbc.getAllLgasByRegionType();

        System.out.println("- LGAS:");
        // System.out.println(lgas);

        for (LGA lga : lgas) {
            System.out.println("lga: " + lga.toString());
        }




        HashMap<String, Object> data = new HashMap<>();

        // data.put("lgas", lgas);

        context.render("FocusedView.html", data);
    }
}