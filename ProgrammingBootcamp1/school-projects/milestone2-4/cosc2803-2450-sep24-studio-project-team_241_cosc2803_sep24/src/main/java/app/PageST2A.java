package app;

import java.util.ArrayList;

import io.javalin.http.Context;
import io.javalin.http.Handler;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

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

        // Add HTML for the page content

            html += """
            <div class='lga-section'>
                <label>LGA's (2019 - 2020)</label><br>
                <button class='lga-btn'>Albury</button>
                <button class='lga-btn'>Blacktown</button>
                <button class='lga-btn'>Burwood</button>
                <button class='lga-btn'>Broken Hill</button>
                <button class='lga-btn'>Bogan</button>
                <select class='lga-dropdown'>
                    <option>Select a Year</option>
                    <option>2019</option>
                    <option>2020</option>
                </select>
            </div>
        """;

        // Resource Type
        html += """
            <div class='resource-type-section'>
                <label>Resource Type</label><br>
                <button class='resource-type-btn'>Recyclable</button>
                <button class='resource-type-btn'>Organics</button>
                <button class='resource-type-btn'>Waste</button>
            </div>
        """;

        // Resource Sub Type
        html += """
            <div class='resource-subtype-section'>
                <label>Resource Sub Type</label><br>
                <button class='resource-subtype-btn'>Kerbside Recycling</button>
                <button class='resource-subtype-btn'>Drop Off Recycling</button>
                <button class='resource-subtype-btn'>Clean Up</button>
                <button class='resource-subtype-btn'>Organics</button>
                <select class='resource-dropdown'>
                    <option>Select a Sub Type</option>
                    <option>Kerbside</option>
                    <option>Drop Off</option>
                    <option>Clean Up</option>
                    <option>Organics</option>
                </select>
            </div>
        """;

        // Apply and Sort buttons
        html += """
            <div class='buttons'>
                <button class='apply-btn'>Sort</button>
                <button class='apply-btn'>Apply</button>
            </div>
        """;

        // Table Section
        html += """
            <div class='table-section'>
                <table>
                    <tr>
                        <th>LGA</th>
                        <th>Population</th>
                        <th>Waste Resource Subtype Combo</th>
                        <th>Total Waste Collected</th>
                        <th>Total Waste Recycled</th>
                        <th>Avg Waste Recycled</th>
                    </tr>
                    <tr><td colspan="6">&nbsp;</td></tr>
                    <tr><td colspan="6">&nbsp;</td></tr>
                    <tr><td colspan="6">&nbsp;</td></tr>
                    <tr><td colspan="6">&nbsp;</td></tr>
                </table>
            </div>
        """;

        // Close Content div
        html = html + "</div>";



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

}
