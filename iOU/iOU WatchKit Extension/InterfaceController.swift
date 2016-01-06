//
//  InterfaceController.swift
//  iOU WatchKit Extension
//
//  Created by Dominick Hera on 3/26/15.
//  Copyright (c) 2015 Posa. All rights reserved.
//

import WatchKit
import Foundation


class InterfaceController: WKInterfaceController {

    
    @IBOutlet weak var tableView: WKInterfaceTable!
       var tableData = ["this", "is", "a", "test"]
    override func awakeWithContext(context: AnyObject?) {
        super.awakeWithContext(context)
        
        // Configure interface objects here.
        
        loadTableData()
    }

    override func willActivate() {
        // This method is called when watch view controller is about to be visible to user
        super.willActivate()
    }

    override func didDeactivate() {
        // This method is called when watch view controller is no longer visible
        super.didDeactivate()
    }
    // Load table into the data
    func loadTableData() {
        // Set total row count. Remember our identifier was Cell
        //tableView.setNumberOfRows(tableData.count, withRowType: "rowThing")
        tableView.setNumberOfRows(tableData.count, withRowType: "rowThing")
        
        var i = 0 // Used to count each item
        for item in tableData { // Loop over each item in tableData
            let row = tableView.rowControllerAtIndex(i) as! TableRowObject // Get a single row object for the current item
            row.lblTblRowItem.setText(item) // Set the row text to the corresponding item
            i++ // Move onto the next item
        }
        
    }
    
}

