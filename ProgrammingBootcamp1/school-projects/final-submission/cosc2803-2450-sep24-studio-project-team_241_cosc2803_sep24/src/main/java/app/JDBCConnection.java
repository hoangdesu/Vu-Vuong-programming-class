package app;

import java.util.ArrayList;
import java.util.HashMap;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * Class for Managing the JDBC Connection to a SQLLite Database.
 * Allows SQL queries to be used with the SQLLite Databse in Java.
 *
 * @author Timothy Wiley, 2023. email: timothy.wiley@rmit.edu.au
 * @author Santha Sumanasekara, 2021. email: santha.sumanasekara@rmit.edu.au
 * @author Halil Ali, 2024. email: halil.ali@rmit.edu.au
 */

public class JDBCConnection {

  // Name of database file (contained in database folder)
  public static final String DATABASE = "jdbc:sqlite:database/WasteRecycling.db";

  /**
   * This creates a JDBC Object so we can keep talking to the database
   */
  public JDBCConnection() {
    System.out.println("Created JDBC Connection Object");
  }

  public Connection connect() {
    Connection conn = null;
    try {
      conn = DriverManager.getConnection(DATABASE);
      // System.out.println("Connection to SQLite has been established.");
    } catch (SQLException e) {
      System.out.println(e.getMessage());
    }
    return conn;
  }

  /**
   * Get all of the Countries in the database.
   * 
   * @return
   *         Returns an ArrayList of LGA objects
   */
  public ArrayList<LGA> getAllCountries() {
    // Create the ArrayList of LGA objects to return
    ArrayList<LGA> lgas = new ArrayList<LGA>();

    // Setup the variable for the JDBC connection
    Connection connection = null;

    try {
      // Connect to JDBC data base
      connection = DriverManager.getConnection(DATABASE);

      // Prepare a new SQL Query & Set a timeout
      Statement statement = connection.createStatement();
      statement.setQueryTimeout(30);

      // The Query
      String query = "SELECT * FROM lga";

      // Get Result
      ResultSet results = statement.executeQuery(query);

      // Process all of the results
      while (results.next()) {
        // Lookup the columns we need
        int code = results.getInt("code");
        String name = results.getString("name");

        // Create an LGA Object
        LGA lga = new LGA(code, name);

        // Add the LGA object to the array
        lgas.add(lga);
      }

      // Close the statement because we are done with it
      statement.close();
    } catch (SQLException e) {
      // If there is an error, lets just pring the error
      System.err.println(e.getMessage());
    } finally {
      // Safety code to cleanup
      try {
        if (connection != null) {
          connection.close();
        }
      } catch (SQLException e) {
        // connection close failed.
        System.err.println(e.getMessage());
      }
    }

    // Finally we return all of the countries
    return lgas;
  }

  public ArrayList<LGA> getAllLgasByRegionType() {
    ArrayList<LGA> lgas = new ArrayList<>();

    String query = """
        SELECT Lga.code, Lga.name, RegionType.name AS RegionType FROM Lga
          JOIN RegionType
          ON Lga.regionType = RegionType.regionType
          ;
          """;

    try (
        Connection conn = this.connect();
        PreparedStatement pstmt = conn.prepareStatement(query)) {
      try (ResultSet rs = pstmt.executeQuery()) {
        while (rs.next()) {
          int code = rs.getInt("code");
          String name = rs.getString("name");
          String regionType = rs.getString("RegionType");

          LGA lga = new LGA(code, name, regionType);
          // System.out.println("Adding LGA: " + lga.toString());

          lgas.add(lga);
        }
      }
    } catch (SQLException e) {
      System.out.println(e.getMessage());
    }

    return lgas;
  }

  // public double[] getRegionalOrganicCollectedWasteDifference(
  public HashMap<String, Object> getRegionalOrganicCollectedWasteDifference(
      String areaData, // SMA
      String yearStart, // e.g. 2016
      String yearEnd // e.g. 2021

  ) {
    HashMap<String, Object> map = new HashMap<>();

    String query = """
        SELECT AREA, Years, Collected, Recycled
        FROM RegionalOrganics
        WHERE AREA LIKE ?
        AND (Years LIKE ? OR Years LIKE ?)
        ORDER BY Years;
            """;


            // String.format("""
            //      SELECT AREA, Years, Collected, Recycled
            //       FROM RegionalOrganics
            //       WHERE AREA LIKE %s
            //       AND (Years LIKE %s OR Years LIKE %s)
            //       ORDER BY Years;
            //     """, "a", "b", "c");

    System.out.println("running getRegionalOrganicCollectedWasteDifference");
    System.out.println(yearStart + " " + yearEnd);

    // waste collected
    double collectedStart = 0.0;
    double collectedEnd = 0.0;
    double collectedDifference = 0.0;
    double collectedPercentage = 0.0;

    // waste recycled
    double recycledStart = 0.0;
    double recycledEnd = 0.0;
    double recycledDifference = 0.0;
    double recycledPercentage = 0.0;

    try (
        Connection conn = this.connect();
        PreparedStatement pstmt = conn.prepareStatement(query);) {
      System.out.println("");
      String shortAreaData = areaData;
      System.out.println("shortAreaData" + shortAreaData);
      pstmt.setString(1, areaData);

      // String shortYearStart = String.valueOf(yearStart).substring(2); // 2016 ->
      // '2016' -> 16
      String shortYearStart = "__" + yearStart.substring(2) + "%"; // e.g., "16" -> "__16%"
      System.out.println("shortYearStart" + shortYearStart);
      pstmt.setString(2, shortYearStart);

      // String shortYearEnd = String.valueOf(yearEnd).substring(2); // 2016 -> '2016'
      // -> 16
      String shortYearEnd = "%" + yearEnd.substring(2); // e.g., "21" -> "%21"
      System.out.println("shortYearEnd" + shortYearEnd);
      pstmt.setString(3, shortYearEnd);

      // ArrayList<HashMap<String, Object>> results = new ArrayList<>();

      try (ResultSet rs = pstmt.executeQuery()) {
        // while (rs.next()) {
        //  ... 
        // }
      
        if (rs.next()) {
          double prevCollected = rs.getDouble("Collected");
          collectedStart = prevCollected;
          map.put("collectedStart", collectedStart);

          double prevRecycled = rs.getDouble("Recycled");
          recycledStart = prevRecycled;
          map.put("recycledStart", recycledStart);

          if (rs.next()) {
            double nextCollected = rs.getDouble("Collected");
            double nextRecycled = rs.getDouble("Recycled");

            collectedEnd = nextCollected;
            recycledEnd = nextRecycled;

            map.put("collectedEnd", collectedEnd);
            map.put("recycledEnd", recycledEnd);

            // Calculate differences
            collectedDifference = nextCollected - prevCollected;
            collectedPercentage = (collectedDifference / prevCollected) * 100;

            map.put("collectedDifference", String.format("%.2f", collectedDifference));
            map.put("collectedPercentage", String.format("%.2f%%", collectedPercentage));

            recycledDifference = nextRecycled - prevRecycled;
            recycledPercentage = (recycledDifference / prevRecycled) * 100;

            map.put("recycledDifference", String.format("%.2f", recycledDifference));
            map.put("recycledPercentage", String.format("%.2f%%", recycledPercentage));

            System.out.println("prevCollected: " + prevCollected);
            System.out.println("prevRecycled: " + prevRecycled);
            System.out.println("nextCollected: " + nextCollected);
            System.out.println("nextCollected: " + nextCollected);

            System.out.println("Collected Difference: " + collectedDifference);
            System.out.println("Collected Percentage: " + collectedPercentage);
            System.out.println("Recycled Difference: " + recycledDifference);
            System.out.println("Recycled Percentage: " + recycledPercentage);
          }
        }
      }
    } catch (SQLException e) {
      System.err.println("Database error: " + e.getMessage());
    }

    return map;
  }

}
