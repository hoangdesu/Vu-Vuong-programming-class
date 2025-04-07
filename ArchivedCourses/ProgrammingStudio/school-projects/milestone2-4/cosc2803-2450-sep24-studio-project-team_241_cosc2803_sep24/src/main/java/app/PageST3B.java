package app;

import io.javalin.http.Context;
import io.javalin.http.Handler;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.HashMap;

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
    JDBCConnection jdbcConnection = new JDBCConnection();

    String fromYear = context.formParam("fromYear");
    String toYear = context.formParam("toYear");

    System.out.println("--- server");
    System.out.println("from to years: " + fromYear + " " + toYear);

    double difference[] = jdbcConnection.getRegionalOrganicCollectedWasteDifference(
      "2016",
      "2021"
    );

    HashMap<String, Object> data = new HashMap<>();

    // put data here
    data.put("difference", difference);

    context.render("IdentifyChanges.html", data);
  }
}
