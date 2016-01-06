//
//  LoanTableViewController.swift
//  iOU 4.0
//
//  Created by Dominick Hera on 11/11/14.
//  Copyright (c) 2014 Posa. All rights reserved.
//

import UIKit
import CoreData
import QuartzCore

class LoanTableViewController: UITableViewController {
    
    var iOU_4_0 : Array <AnyObject> = []
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print("hi")

    }
    
    override func viewDidAppear(animated: Bool) {
      
        let appDel:AppDelegate = UIApplication.sharedApplication().delegate as! AppDelegate
        let context:NSManagedObjectContext = appDel.managedObjectContext!
        let freq = NSFetchRequest(entityName: "Loans")
        
        iOU_4_0 = context.executeFetchRequest(freq, error: nil)!
        
        tableView.reloadData()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    // MARK: - Table view data source

    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        // #warning Potentially incomplete method implementation.
        // Return the number of sections.
        return 1
    }
    
    override func tableView(tableView: UITableView, canEditRowAtIndexPath indexPath: NSIndexPath) -> Bool {
        // Return false if you do not want the specified item to be editable.
        return true
    }

    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete method implementation.
        // Return the number of rows in the section.
        //
        return iOU_4_0.count
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        let CellID: NSString = "Cell"
        let cell: UITableViewCell = tableView.dequeueReusableCellWithIdentifier(CellID as String) as! UITableViewCell
        
        let ip = indexPath
            let data: NSManagedObject = iOU_4_0[ip.row] as! NSManagedObject

          let nme = data.valueForKeyPath("loanRecipient") as! String
          let qnt = data.valueForKeyPath("loanAmount") as! String
          let inf = data.valueForKeyPath("loanNotes") as! String
          var dte = data.valueForKeyPath("dateLabel") as! String
        
          cell.textLabel?.text = "\(nme)'s Loan is Due \(dte)"
          cell.detailTextLabel?.text = "$\(qnt) - \(inf)"
        
        return cell
        
        }
            /*  var indexPath: NSIndexPath = self.tableView.indexPathForSelectedRow()!
            var selectedItem: NSManagedObject = iOU_4_0[indexPath.row] as NSManagedObject
            
            let LCVC: LoanCreateViewController = segue.destinationViewController as LoanCreateViewController
            
            LCVC.loanRecipient = selectedItem.valueForKey("loanRecipient") as String
            LCVC.loanAmount = selectedItem.valueForKey("loanAmount") as String
            LCVC.loanNotes = selectedItem.valueForKey("loanNotes") as String
            LCVC.dateLabel = selectedItem.valueForKey("dateLabel") as String
            LCVC.existingItem = selectedItem */

 //  }
//}
    
     override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject!) {
        
        if segue.identifier == "showDetail" {
            
            let controller = segue.destinationViewController as! DetailViewController
            let row = tableView.indexPathForSelectedRow!.row
            print("row: \(row)")
            let loan = iOU_4_0[row] as! NSManagedObject
            print(loan)
            controller.loanPersonPass = iOU_4_0[row] as? NSManagedObject
        }
    }
    
    override func tableView(tableView: UITableView, moveRowAtIndexPath fromIndexPath: NSIndexPath, toIndexPath: NSIndexPath) {
        let itemToMove: AnyObject = iOU_4_0[fromIndexPath.row]
        iOU_4_0.removeAtIndex(fromIndexPath.row)
        iOU_4_0.insert(itemToMove, atIndex: toIndexPath.row)
        
    }
    
    override func tableView(tableView: UITableView, canMoveRowAtIndexPath indexPath: NSIndexPath) -> Bool {
        return true
    }
    @IBAction func startEditing(sender: UIBarButtonItem) {
        
            self.editing = !self.editing
        
    }
    
    
    override func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath?) {
        
        let appDel:AppDelegate = UIApplication.sharedApplication().delegate as! AppDelegate
        let context:NSManagedObjectContext = appDel.managedObjectContext!
        
        if editingStyle == UITableViewCellEditingStyle.Delete {
            
           if let tv = self.tableView {
              context.deleteObject(iOU_4_0[indexPath!.row] as! NSManagedObject )
                iOU_4_0.removeAtIndex(indexPath!.row)
                tv.deleteRowsAtIndexPaths([indexPath!], withRowAnimation: UITableViewRowAnimation.Fade)
            }
            
          //var error: NSError? = nil
           // if !context.save(&error) {
              //  abort()
        }
        
        /*func tableView(tableView: UITableView!, didSelectRowAtIndexPath segue: UIStoryboardSegue, indexPath: NSIndexPath!) {
            
           //Create instance of DetailVC
            var detail:DetailViewController = self.storyboard.instantiateViewControllerWithIdentifier("DetailViewController") as DetailViewController
            
            //Reference DetailVC's var "cellName" and assign it to this controller's var "items"
            detail.nameFinalString = self.iOU_4_0[indexPath.row]
            
            //Programmatically push to associated VC (DetailVC)
            self.navigationController.pushViewController(detail, animated: true)*/
            //}
        }
    
    }

