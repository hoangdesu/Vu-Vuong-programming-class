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

public class PageST3A implements Handler {

    // URL of this page relative to http://localhost:7001/
    public static final String URL = "/page3A.html";

    @Override
    public void handle(Context context) throws Exception {
        // Create a simple HTML webpage in a String
        String html = "<html>";

        // Add some Head information
        html = html + "<head>" + 
               "<title>Simlar LGA'S</title>" +
               "<style>" +
                "body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; }" +
                ".topnav { background-color: #333; overflow: hidden; padding: 10px; }" +
                ".topnav a { color: #f4f4f4; padding: 14px 20px; text-decoration: none; display: inline-block; }" +
                ".topnav a:hover { background-color: #575757; }" +
                ".header { text-align: center; padding: 20px; }" +
                ".content { padding: 20px; }" +
                ".section { margin-bottom: 20px; }" +
                ".label { font-weight: bold; margin-bottom: 5px; display: block; }" +
                ".btn { background-color: #1E90FF; color: white; border: none; padding: 8px 16px; cursor: pointer; margin: 5px; border-radius: 4px; }" +
                ".btn:hover { background-color: #1C86EE; }" +
                ".selected-display { background-color: #FFD700; color: black; font-weight: bold; padding: 8px 16px; border: none; cursor: default; border-radius: 4px; }" +
                ".dropdown { padding: 8px; margin: 5px; border-radius: 4px; }" +
                ".apply-btn { background-color: #28a745; color: white; border: none; padding: 10px 20px; font-size: 16px; cursor: pointer; border-radius: 5px; font-weight: bold; }" +
                ".apply-btn:hover { background-color: #218838; }" +
                ".table-section { width: 100%; margin-top: 20px; }" +
                "table { width: 100%; border-collapse: collapse; margin-top: 20px; }" +
                "th, td { padding: 12px; text-align: center; border: 1px solid #ddd; }" +
                "th { background-color: #333; color: #f4f4f4; font-weight: bold; }" +
                ".footer { background-color: #333; color: #f4f4f4; text-align: center; padding: 10px; position: relative; bottom: 0; width: 100%; margin-top: 20px; }" +
                ".footer button { background-color: #333; color: #f4f4f4; border: none; padding: 10px 20px; cursor: pointer; margin: 5px; font-size: 14px; border-radius: 5px; }" +
                ".footer button:hover { background-color: #575757; }" +
                ".filters { display: flex; align-items: center; justify-content: space-between; margin-bottom: 20px; }" +
                ".filter-group { display: flex; flex-direction: column; align-items: flex-start; }" +
                "</style>" +
                "<script>" +
                "function selectOption(button, displayId) {" +
                "   var buttons = button.parentElement.getElementsByClassName('btn');" +
                "   for (var i = 0; i < buttons.length; i++) {" +
                "       buttons[i].classList.remove('selected');" +
                "   }" +
                "   button.classList.add('selected');" +
                "   document.getElementById(displayId).innerText = button.innerText;" +
                "}" +
                "</script>" +
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
                <h1>Similar LGA'S</h1>
            </div>
        """;

        // Add Div for page Content
        // LGA Selection
        html += """
            <div class='section'>
                <span class='label'>Select LGA's</span>
                <button class='btn' onclick='selectOption(this, "selectedLGA")'>Albury</button>
                <button class='btn' onclick='selectOption(this, "selectedLGA")'>Blacktown</button>
                <button class='btn' onclick='selectOption(this, "selectedLGA")'>Burwood</button>
                <button class='btn' onclick='selectOption(this, "selectedLGA")'>Broken Hill</button>
                <button class='btn' onclick='selectOption(this, "selectedLGA")'>Bogan</button>
                <select class='dropdown'>
                    <option>Click for more</option>
                    <option>More Options...</option>
                </select>
                <button id='selectedLGA' class='selected-display'>Selected LGA</button>
            </div>
        """;

        // Resource Type
        html += """
            <div class='section'>
                <span class='label'>Resource Type</span>
                <button class='btn' onclick='selectOption(this, "selectedResource")'>Recyclable</button>
                <button class='btn' onclick='selectOption(this, "selectedResource")'>Organics</button>
                <button class='btn' onclick='selectOption(this, "selectedResource")'>Waste</button>
                <button id='selectedResource' class='selected-display'>Selected Resource</button>
            </div>
        """;

        // Resource Sub Type
        html += """
            <div class='section'>
                <span class='label'>Resource Sub Type</span>
                <button class='btn' onclick='selectOption(this, "selectedSubType")'>Kerbside Recycling</button>
                <button class='btn' onclick='selectOption(this, "selectedSubType")'>Drop Off</button>
                <button class='btn' onclick='selectOption(this, "selectedSubType")'>Clean Up</button>
                <button class='btn' onclick='selectOption(this, "selectedSubType")'>Organics</button>
                <select class='dropdown'>
                    <option>Select Sub Type</option>
                    <option>Sub Type 1</option>
                    <option>Sub Type 2</option>
                </select>
                <button id='selectedSubType' class='selected-display'>Selected Sub Type</button>
            </div>
        """;

        // Additional Filters
        html += """
            <div class='filters'>
                <div class='filter-group'>
                    <span class='label'>Period</span>
                    <button class='btn'>2018-2019</button>
                    <button class='btn'>2019-2020</button>
                </div>
                <div class='filter-group'>
                    <span class='label'>Cut-off Value</span>
                    <input type='text' placeholder='Enter value' class='dropdown' style='width: 150px;'/>
                </div>
                <button class='apply-btn'>Apply</button>
            </div>
        """;

        // Table Section
        html += """
            <div class='table-section'>
                <table>
                    <tr>
                        <th class='table-header'>LGA</th>
                        <th class='table-header'>Percentage of Waste Recycled for each subtype</th>
                        <th class='table-header'>Similarity to the selected LGA</th>
                    </tr>
                    <tr><td colspan='3'>&nbsp;</td></tr>
                    <tr><td colspan='3'>&nbsp;</td></tr>
                    <tr><td colspan='3'>&nbsp;</td></tr>
                    <tr><td colspan='3'>&nbsp;</td></tr>
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
