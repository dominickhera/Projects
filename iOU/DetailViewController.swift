//
//  DetailViewController.swift
//  iOU 4.0
//
//  Created by Dominick Hera on 11/20/14.
//  Copyright (c) 2014 Posa. All rights reserved.
//

import UIKit
import CoreData
import EventKit

class DetailViewController: UIViewController {
    
    var loanPersonPass: NSManagedObject?
    var eventStore = EKEventStore()
    var appDelegate: AppDelegate?
   
    @IBOutlet weak var nameLoanInfoLabel: UILabel!
    @IBOutlet weak var amountLoanInfoLabel: UILabel!
    @IBOutlet weak var notesLoanInfoLabel: UILabel!
    @IBOutlet weak var dateLoanInfoLabel: UILabel!

    
    override func viewDidLoad() {
        super.viewDidLoad()
        
       /* let eventStore = EKEventStore()
        
        // 2
        switch EKEventStore.authorizationStatusForEntityType(EKEntityTypeEvent) {
        case .Authorized:
            addEvent(eventStore)
        case .Denied:
            println("Access denied")
        case .NotDetermined:
            // 3
            eventStore.requestAccessToEntityType(EKEntityTypeEvent, completion:
                {[weak self] (granted: Bool, error: NSError!) -> Void in
                    if granted {
                        self!.addEvent(eventStore)
                    } else {
                        println("Access denied")
                    }
            })
        default:
            println("Case Default")
        }
         */
        
        navigationItem.title = "Loan Information"
        
        var lil = retrieveFromLoan("loanRecipient")
        var alil = retrieveFromLoan("loanAmount")
        var nlil = retrieveFromLoan("loanNotes")
        var dlil = retrieveFromLoan("dateLabel")
        
        
       // nameLoanInfoLabel.text = "\(lil) has a loan of $\(alil)"
        //amountLoanInfoLabel.text = "for \(nlil) that is due on \(dlil)"
        //notesLoanInfoLabel.text = ""
        //dateLoanInfoLabel.text = ""
        nameLoanInfoLabel.text = "Recipient: " + retrieveFromLoan("loanRecipient")
        amountLoanInfoLabel.text = "Amount: $" + retrieveFromLoan("loanAmount")
        notesLoanInfoLabel.text = "Notes: " + retrieveFromLoan("loanNotes")
        dateLoanInfoLabel.text = "Due Date: " + retrieveFromLoan("dateLabel")
        
       }
    
    func retrieveFromLoan(key: String) -> String {
        return loanPersonPass!.valueForKeyPath(key) as! String
    }
    
    @IBAction func addEvent(store: EKEventStore) {
        
     /*  let calendars = eventStore.calendarsForEntityType(EKEntityTypeEvent)
            as [EKCalendar]
        
        for calendar in calendars {
            // 2
            if calendar.title == "Loans" {
                // 3
                let startDate = NSDate()
                // 2 hours
                let endDate = startDate.dateByAddingTimeInterval(2 * 60 * 60)
                
                // 4
                // Create Event
                var event = EKEvent(eventStore: store)
                event.calendar = calendar
                
                event.title = "A Loan is Due"
                event.startDate = startDate
                event.endDate = endDate
                
                // 5
                // Save Event in Calendar
                var error: NSError?
                let result = store.saveEvent(event, span: EKSpanThisEvent, error: &error)
                
                if result == false {
                    if let theError = error {
                        println("An error occured \(theError)")
                    }
                }
            }
        }*/
       }
    @IBAction func shareTapped(sender: AnyObject) {
        
        var lil = retrieveFromLoan("loanRecipient")
        var alil = retrieveFromLoan("loanAmount")
        var nlil = retrieveFromLoan("loanNotes")
        var dlil = retrieveFromLoan("dateLabel")
        
        /*let link = NSURL(string: "http://posacorp.com")*/
        let sc = UIActivityViewController(activityItems: ["\(lil) has a loan of $\(alil) for \(nlil) that needs to be paid back by \(dlil)"], applicationActivities: nil)
        self.presentViewController(sc, animated: true, completion: nil)
    
    
    
     /*   // 1
        let optionMenu = UIAlertController(title: nil, message: "Choose Option", preferredStyle: .ActionSheet)
        
        // 2
        let deleteAction = UIAlertAction(title: "Share", style: .Default, handler: {
            (alert: UIAlertAction!) -> Void in
            println("File Shared")
        })
        let saveAction = UIAlertAction(title: "Save", style: .Default, handler: {
            (alert: UIAlertAction!) -> Void in
            println("File Saved")
        })
        
        //
        let cancelAction = UIAlertAction(title: "Cancel", style: .Cancel, handler: {
            (alert: UIAlertAction!) -> Void in
            println("Cancelled")
        })
        
        
        // 4
        optionMenu.addAction(deleteAction)
        optionMenu.addAction(saveAction)
        optionMenu.addAction(cancelAction)
        
        // 5
        self.presentViewController(optionMenu, animated: true, completion: nil)*/
        }
    }