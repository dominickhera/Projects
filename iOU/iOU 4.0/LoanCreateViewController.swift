//
//  LoanCreateViewController.swift
//  iOU 4.0
//
//  Created by Dominick Hera on 11/11/14.
//  Copyright (c) 2014 Posa. All rights reserved.
//

import UIKit
import CoreData

class LoanCreateViewController: UIViewController {

    @IBOutlet weak var loanRecipientField: UITextField! = nil
    @IBOutlet weak var loanAmountField: UITextField! = nil
    @IBOutlet weak var loanNotesField: UITextField! = nil
    @IBOutlet weak var datePicker: UIDatePicker! = nil
    @IBOutlet weak var dateLabelField: UITextField! = nil
    
    var loanAmount: String = ""
    var loanNotes: String = ""
    var loanRecipient: String = ""
    var dateLabel: String = ""
    
    var existingItem: NSManagedObject!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
       /* if (loanRecipientField.text.isEmpty) {
            let alert = UIAlertView()
            alert.title = "No Text"
            alert.message = "Please Enter Text In The Box"
            alert.addButtonWithTitle("Ok")
            alert.show()
            
            return false
            
        }
        
        else{
            return true
    
        }*/

        
        if (existingItem != nil) {
            
            loanRecipientField.text = loanRecipient
            loanAmountField.text = loanAmount
            loanNotesField.text = loanNotes
            dateLabelField.text = dateLabel
        }
        
        func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
           // if (segue.identifier == "showDetail") {
           //     var svc = segue.destinationViewController as DetailViewController
                
           //     svc.toPass = loanRecipient
        //   }
        }
        datePicker.addTarget(self, action: Selector("datePickerChanged:"), forControlEvents: UIControlEvents.ValueChanged)
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector:"drawAShape:", name: "actionOnePressed", object: nil)
        NSNotificationCenter.defaultCenter().addObserver(self, selector:"showAMessage:", name: "actionTwoPressed", object: nil)
        
        let dateComp:NSDateComponents = NSDateComponents()
        dateComp.year = 2015;
        dateComp.month = 01;
        dateComp.day = 20;
        dateComp.hour = 10;
        dateComp.minute = 37;
        dateComp.timeZone = NSTimeZone.systemTimeZone()
        
        let calender:NSCalendar = NSCalendar(calendarIdentifier: NSGregorianCalendar)!
        let date:NSDate = calender.dateFromComponents(dateComp)!
        
        
        let notification:UILocalNotification = UILocalNotification()
        notification.category = "FIRST_CATEGORY"
        notification.alertBody = "Hi, I am a notification"
        notification.fireDate = date
        
        UIApplication.sharedApplication().scheduleLocalNotification(notification)

        // Do any additional setup after loading the view.
    }
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        
        return true;
}
    
    func drawAShape(notification:NSNotification){
        let view:UIView = UIView(frame:CGRectMake(10, 10, 100, 100))
        view.backgroundColor = UIColor.redColor()
        
        self.view.addSubview(view)
}
    func showAMessage(notification:NSNotification){
        var message:UIAlertController = UIAlertController(title: "A Notification Message", message: "Test", preferredStyle: UIAlertControllerStyle.Alert)
        message.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.Default, handler: nil))
        
        self.presentViewController(message, animated: true, completion: nil)
}
    
    func datePickerChanged(datePicker:UIDatePicker) {
        var dateFormatter = NSDateFormatter()
        
        dateFormatter.dateStyle = NSDateFormatterStyle.ShortStyle
        //dateFormatter.timeStyle = NSDateFormatterStyle.ShortStyle
        
        var strDate = dateFormatter.stringFromDate(datePicker.date)
        dateLabelField.text = strDate
        
}
    @IBAction func saveTapped(sender: AnyObject) {
    
        
        let addDel: AppDelegate = UIApplication.sharedApplication().delegate as! AppDelegate
        
        let contxt: NSManagedObjectContext = addDel.managedObjectContext!
        let en = NSEntityDescription.entityForName("Loans", inManagedObjectContext: contxt)
        
        if (loanAmountField.text!.isEmpty){
                
                let alert = UIAlertView()
                alert.title = "Missing Text"
                alert.message = "Please enter text in to all text fields"
                alert.addButtonWithTitle("OK")
                alert.show()
                
            }
            else {
                
                if (loanNotesField.text.isEmpty){
                    
                    let alert = UIAlertView()
                    alert.title = "Missing Text"
                    alert.message = "Please enter text in to all text fields"
                    alert.addButtonWithTitle("OK")
                    alert.show()
                    
                }
                else {
                    
                    if (dateLabelField.text.isEmpty){
                        
                        let alert = UIAlertView()
                        alert.title = "Missing Text"
                        alert.message = "Please enter text in to all text fields"
                        alert.addButtonWithTitle("OK")
                        alert.show()
                        
                    }
                    
                    else{
        if (existingItem != nil) {
            existingItem.setValue(loanRecipientField.text as String, forKey: "loanRecipient")
            existingItem.setValue(loanAmountField.text as String, forKey: "loanAmount")
            existingItem.setValue(loanNotesField.text as String, forKey: "loanNotes")
            existingItem.setValue(dateLabelField.text as String, forKey: "dateLabel")
        } else {
            
          var newLoan = Model(entity: en!, insertIntoManagedObjectContext: contxt)
        
        newLoan.loanRecipient = loanRecipientField.text
        newLoan.loanAmount = loanAmountField.text
        newLoan.loanNotes = loanNotesField.text
        newLoan.dateLabel = dateLabelField.text
        
        }
        
        if (loanRecipientField.text.isEmpty){
            
            let alert = UIAlertView()
            alert.title = "Missing Text"
            alert.message = "Please enter text in to all text fields"
            alert.addButtonWithTitle("OK")
            alert.show()
           // contxt.save(nil)
            
        }
        else {
    
            
                    //else {
                
        contxt.save(nil)
        
        self.navigationController?.popToRootViewControllerAnimated(true)
                    }
                }
            }
        }
    }
    @IBAction func cancelTapped(sender: AnyObject) {
        
        self.navigationController?.popToRootViewControllerAnimated(true)
    }
    
    @IBAction func addContactTapped(sender: AnyObject) {
        
        // 1
        let optionMenu = UIAlertController(title: nil, message: "Choose Option", preferredStyle: .ActionSheet)
        
        // 2
        let deleteAction = UIAlertAction(title: "Delete", style: .Default, handler: {
            (alert: UIAlertAction!) -> Void in
            print("File Deleted")
        })
        let saveAction = UIAlertAction(title: "Save", style: .Default, handler: {
            (alert: UIAlertAction!) -> Void in
            print("File Saved")
        })
        
        //
        let cancelAction = UIAlertAction(title: "Cancel", style: .Cancel, handler: {
            (alert: UIAlertAction!) -> Void in
            print("Cancelled")
        })
        
        // 4
        optionMenu.addAction(deleteAction)
        optionMenu.addAction(saveAction)
        optionMenu.addAction(cancelAction)
        
        // 5
        self.presentViewController(optionMenu, animated: true, completion: nil)

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
   /*  override func touchesBegan(touches: NSSet, withEvent event: UIEvent) {
        self.view.endEditing(true)
    }*/
}
