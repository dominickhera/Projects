//
//  Model.swift
//  iOU 4.0
//
//  Created by Dominick Hera on 11/11/14.
//  Copyright (c) 2014 Posa. All rights reserved.
//

import UIKit
import CoreData

@objc(Model)
class Model: NSManagedObject {
    
    @NSManaged var loanAmount: String
    @NSManaged var loanRecipient: String
    @NSManaged var loanNotes: String
    @NSManaged var dateLabel: String
   
}
