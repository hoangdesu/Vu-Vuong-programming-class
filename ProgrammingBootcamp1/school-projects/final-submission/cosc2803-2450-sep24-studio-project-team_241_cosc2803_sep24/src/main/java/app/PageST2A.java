package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

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

public class PageST2A implements Handler {

    // URL of this page relative to http://localhost:7001/
    public static final String URL = "/page2A.html";

    @Override
    public void handle(Context context) throws Exception {
        // Create a simple HTML webpage in a String
        String html = "<html>";

        // Add some Head information
        html = html + "<head>" + 
               "<title>Subtask 2.1</title>"+
               "<style>" +
                "body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; }" +
                ".topnav { background-color: #333; overflow: hidden; padding: 10px; }" +
                ".topnav a { color: #f4f4f4; padding: 14px 20px; text-decoration: none; display: inline-block; }" +
                ".topnav a:hover { background-color: #575757; }" +
                ".header { text-align: center; padding: 20px; }" +
                ".content { padding: 20px; }" +
                ".lga-section, .resource-type-section, .resource-subtype-section { margin-bottom: 20px; }" +
                ".lga-btn, .resource-type-btn, .resource-subtype-btn, .apply-btn { background-color: #333; color: #f4f4f4; border: none; padding: 10px 20px; cursor: pointer; margin: 5px; font-size: 14px; border-radius: 5px; }" +
                ".lga-btn:hover, .resource-type-btn:hover, .resource-subtype-btn:hover, .apply-btn:hover { background-color: #575757; }" +
                ".table-section { margin-top: 20px; width: 100%; }" +
                "table { width: 100%; border-collapse: collapse; margin-top: 20px; }" +
                "th, td { padding: 12px; text-align: center; border: 1px solid #ddd; }" +
                "th { background-color: #333; color: #f4f4f4; }" +
                ".footer { background-color: #333; color: #f4f4f4; text-align: center; padding: 10px; position: relative; bottom: 0; width: 100%; margin-top: 20px; }" +
                ".footer button { background-color: #333; color: #f4f4f4; border: none; padding: 10px 20px; cursor: pointer; margin: 5px; font-size: 14px; border-radius: 5px; }" +
                ".footer button:hover { background-color: #575757; }" +
                "</style>" +
                "</head>";

        // Add some CSS (external file)
        html = html + "<link rel='stylesheet' type='text/css' href='common.css' />";
        html = html + "</head>";

        // Add the body
        html = html + "<body>";

        // Add the topnav
        // This uses a Java v15+ Text Block
        html += """
            <div class='topnav'>
                <a href='/'>Homepage</a>
                <a href='mission.html'>Our Mission</a>
                <a href='page2A.html'>LGA (2019-2020)</a>
                <a href='page2B.html'>Focused View</a>
                <a href='page3A.html'>Similar LGAs</a>
                <a href='page3B.html'>Identify Changes</a>
            </div>
        """;

        // Add header content block
        html = html + """
            <div class='header'>
                <h1>LGA'S (2019-2020)</h1>
            </div>
        """;

        // Add Div for page Content
        html = html + "<div class='content'>";


        ArrayList<String> lgas = getLGA();
        if (lgas.isEmpty()) {
            html += "<p style='color:red;'>Error: No LGAs found. Check database connection and query.</p>";
        }
        html += "<div class='lga-section'><label for='LGA_drop'>Select LGAs:</label>";
        html += "<select id='LGA_drop' name='LGA_drop' multiple>";
        for (String lga : lgas) {
            html += "<option>" + lga + "</option>";
        }
        html += "</select></div>";

        // Resource Type

        html += "<div class='form-group col-md-4'><label for='resource_drop' class='form-names'>Select a resource:</label>";
        html += "<select id='resource_drop' name='resource_drop' class='form-control' onchange='updateSubtypes()'>";
        html += "<option value=''>-- Select Resource Type --</option>";
        html += "<option value='recyclable'>Recyclable</option>";
        html += "<option value='organics'>Organics</option>";
        html += "<option value='waste'>Waste</option>";
        html += "</select></div>";
        html += "<br><br>";

        // Resource Sub Type

        html += "<label for='subtypes'>Select sub types:</label>";
        html += "<select id='subtypes' name='subtypes' multiple>";
        html = html + " <option> (Recyclable)Kerbside Recycling</option>";
        html = html + " <option>(Recyclable)CDS Recycling</option>";
        html = html + " <option>(Recyclable)Drop off Recycling</option>";
        html = html + " <option>(Recyclable)Cleanup Recycling</option>";
        html = html + " <option>(Organics)Kerbside Waste Bin</option>";
        html = html + " <option>(Organics)Drop Off</option>";
        html = html + " <option>(Organics)Clean up</option>";
        html = html + " <option>(Organics)Kerbside Organics Bin</option>";
        html = html + " <option>(Organics)Kerbside FOGO Organics</option>";
        html = html + " <option>(Waste)Drop off Organics</option>";
        html = html + " <option>(Waste)Cleanup organic</option>";
        html = html + " <option>(Waste)Other Council Organics</option>";

        
        html = html + "</select></div>";
        html = html + "</div></div><br><br>";

        // Apply and Sort buttons

        html = html + "  <label for='sort_drop'class = 'form-names'>Sort</label>";
        html = html + "  <select id='sort_drop' name='sort_drop'>";
        html = html + "  <option>high to low</option>";
        html = html + "  <option>low to high</option>";
        html = html + "  </select>";

         
        html += """
                <button type='submit' class='apply-button'> APPLY </button>

         """;
        
        
        // Table Section
        html += """
            <div class='table-section'>
                <table>
                    <tr>
                        <th>LGA</th>
                        <th>Population</th>
                        <th>Households Surveyed</th>
                        <th>Total Waste Collected</th>
                        <th>Total Waste Recycled</th>
                        <th>Avg Waste Recycled</th>
                        <th>Average Waste Collected per Household</th>
                    </tr>
                    <tr><td colspan="6">&nbsp;</td></tr>
                    <tr><td colspan="6">&nbsp;</td></tr>
                    <tr><td colspan="6">&nbsp;</td></tr>
                    <tr><td colspan="6">&nbsp;</td></tr>
                    <tr><td colspan="6">&nbsp;</td></tr>
                </table>
            </div>
        """;

        // Close Content div
        ArrayList<String> selectedLGAs = new ArrayList<>(); // Populate with actual LGA names as needed
        String resourceType = "recyclable"; // Example
        ArrayList<String> selectedSubtypes = new ArrayList<>(); // Populate as needed
        String sortType = "high to low"; // Example
        String objectType = "Total_SR"; // Example metric to sort by

        ArrayList<String> result2Atable =A2table(selectedLGAs, resourceType, selectedSubtypes, sortType, objectType);

        for (int i = 0; i < result2Atable.size() / 7; ++i) { // 7 columns based on your structure
            html += "<tr>";
            for (int j = 0; j < 7; ++j) {
                html += "<td style='outline: 2px solid;'>" + result2Atable.get((i * 7) + j) + "</td>";
            }
            html += "</tr>";
        }

        // Footer
      // Footer
      html += """
        <div class='footer'>
            <button>FOLLOW US</button>
            <button>ABOUT US</button>
            <button>CONTACT US</button>
        </div>
    """;


        // Finish the HTML webpage
        html = html + "</body>" + "</html>";
        

        // DO NOT MODIFY THIS
        // Makes Javalin render the webpage
        context.html(html);
    }


    public ArrayList<String> A2table(ArrayList<String> lgas, String res, ArrayList<String> subs, String sort,
    String object) {
ArrayList<String> all = new ArrayList<>();
Connection connection = null;


if ("recyclable".equals(res)) {
    res = "LGA_Recyclable19_20";

} else if ("organics".equals(res)) {
    res = "LGA_ORGANIC19_20";
} else if ("waste".equals(res)) {
    res = "LGA_Waste19_20";
}


if (sort.equals("high to low")) {
    sort = "DESC";
} else {
    sort = "ASC";
}

String OBJECT = getobjectfix(object);

try {
    connection = DriverManager.getConnection(JDBCConnection.DATABASE);
    Statement statement = connection.createStatement();
    statement.setQueryTimeout(30);

    for (String lga : lgas) {
        String subSelects = "";
        String totalSC = "";
        String totalSR = "";
        String totalAR = "";
        String totalAW = "";

        for (int i = 0; i < subs.size(); i++) {
            String prefix = getSubPrefix(subs.get(i));

            subSelects += "SUM(" + res + "." + prefix + "Collected) AS SC" + (i + 1) + ", "
                    + "SUM(" + res + "." + prefix + "Recycled) AS SR" + (i + 1) + ", "
                    + "SUM(" + res + "." + prefix + "Recycled) / SUM(" + res + "." + prefix + "Collected) AS AR"
                    + (i + 1) + ", "
                    + "SUM(" + res + "." + prefix
                    + "Collected) / SUM(LGA_Services19_20.Households_Surveyed) AS AW" + (i + 1) + ", ";

            if (i > 0) {
                totalSC += " + ";
                totalSR += " + ";
                totalAR += " + ";
                totalAW += " + ";
            }
            totalSC += "SUM(" + res + "." + prefix + "Collected)";
            totalSR += "SUM(" + res + "." + prefix + "Recycled)";
            totalAR += "SUM(" + res + "." + prefix + "Recycled) / SUM(" + res + "." + prefix + "Collected)";
            totalAW += "SUM(" + res + "." + prefix + "Collected)";
        }

        String query = "SELECT LGA_Services19_20.LGAName, "
                + "SUM(LGA_Services19_20.Population) AS SUM1, "
                + "SUM(LGA_Services19_20.Households Surveyed) AS SUM2, "
                + subSelects
                + "(" + totalSC + ") AS Total_SC, "
                + "(" + totalSR + ") AS Total_SR, "
                + "(" + totalAR + ") AS Total_AR, "
                + "(" + totalAW + " / SUM(LGA_Services19_20.HouseholdsSurveyed)) AS Total_AW "
                + "FROM LGA_Services19_20 "
                + "JOIN " + res + " ON " + res + ".LGACode = LGA_Services19_20.LGACode "
                + "WHERE LGA_Services19_20.LGAName = '" + lga + "' "
                + "GROUP BY LGA_Services19_20.LGAName "
                + "ORDER BY " + OBJECT + " " + sort + ";";
        
        ResultSet results = statement.executeQuery(query);

        while (results.next()) {
            all.add(results.getString("LGA_Name")); 
            all.add(results.getString("SUM1")); 
            all.add(results.getString("SUM2")); 
            all.add(results.getString("Total_SC")); 
            all.add(results.getString("Total_SR")); 
            all.add(results.getString("Total_AR")); 
            all.add(results.getString("Total_AW"));
        }
        System.out.println("Generated SQL Query: " + query);
    }

    statement.close();
} catch (SQLException e) {
    System.err.println(e.getMessage());
} finally {
    try {
        if (connection != null) {
            connection.close();
        }
    } catch (SQLException e) {
        System.err.println(e.getMessage());
    }
}

return all;
}

private String getSubPrefix(String sub) {
    switch (sub) {
        case "(Recyclable)Kerbside Recycling":
            return "K";
        case "(Recyclable)CDS Recycling":
            return "C";
        case "(Recyclable)Drop off Recycling":
            return "D";
        case "(Recyclable)Cleanup Recycling":
            return "Clean";
        case "(Organics)Other Council Organics":
            return "Council";
        case "(Organics)Drop Off":
            return "DropOff";
        case "(Organics)Clean up":
            return "Cleanup";
        case "(Organics)Kerbside Organics Bin":
            return "Kerbside";
        case "(Organics)Kerbside FOGO Organics":
            return "Fogo";
        case "(Waste)Drop off Organics":
            return "DropOff";
        case "(Waste)Cleanup organic":
            return "Cleanup";
        case "(Waste)Kerbside Waste Bin":
            return "Kerbside";
        default:
            return "";
    }





}

private String getobjectfix(String object) {
    switch (object) {
        case "LGA":
            return "LGA_Name";
        case "Population":
            return "SUM1";
        case "Number of Houses Surveyed":
            return "SUM2";
        case "Total Waste Collectedg":
            return "Total_SC";
        case "Total Waste Recycled":
            return "Total_SR";
        case "Average Percentage Recycled (%)":
            return "Total_AR";
        case "Average Waste per Household":
            return "Total_AW";
        default:
            return "";
    }
}

public ArrayList<String> getLGA() {
    ArrayList<String> lgaNames = new ArrayList<>();
    Connection connection = null;
    try {
        connection = DriverManager.getConnection(JDBCConnection.DATABASE);
        Statement statement = connection.createStatement();
        statement.setQueryTimeout(30);
        String query = "SELECT name FROM Lga;";
        System.out.println("Executing query: " + query);  // Debug statement
        ResultSet results = statement.executeQuery(query);

        while (results.next()) {
            String name = results.getString("name");
            lgaNames.add(name);
            System.out.println("Fetched LGA: " + name);  // Debug each fetched LGA
        }
        statement.close();
    } catch (SQLException e) {
        System.err.println("SQL Exception: " + e.getMessage());
    } finally {
        try {
            if (connection != null) connection.close();
        } catch (SQLException e) {
            System.err.println("Closing connection error: " + e.getMessage());
        }
    }
    return lgaNames;
}
}
    
// public ArrayList<String> getLGA() {
//     ArrayList<String> lgasname = new ArrayList<String>();
//     Connection connection = null;
//     try {
//         connection = DriverManager.getConnection(JDBCConnection.DATABASE);
//         Statement statement = connection.createStatement();
//         statement.setQueryTimeout(30);
//         String query = "SELECT name FROM Lga;";
//         ResultSet results = statement.executeQuery(query);
//         while (results.next()) {
//             String name = results.getString("name");
//             // Construct first
//             // String lga = new String();
//             // then use object
//             // object.method
//             // lga.setLGAName(name);

//             lgasname.add(name);
//         }
//         statement.close();
//     } catch (SQLException e) {
//         System.err.println(e.getMessage());
//     } finally {
//         try {
//             if (connection != null) {
//                 connection.close();
//             }
//         } catch (SQLException e) {
//             System.err.println(e.getMessage());
//         }
//     }
//     return lgasname;
// }


