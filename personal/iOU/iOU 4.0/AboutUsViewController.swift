//
//  AboutUsViewController.swift
//  iOU 4.0
//
//  Created by Dominick Hera on 2/12/15.
//  Copyright (c) 2015 Posa. All rights reserved.
//

import UIKit

class AboutUsViewController: UIViewController {

    @IBOutlet weak var aboutUsTextView: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
aboutUsTextView.text = "Hi, my name's Dominick and I'm just some guy on his MacBook Pro coding away to the best of his abilties. I would link social media but I have none. I hope you enjoy the application."
    let fontFamilyNames = UIFont.familyNames()
    for familyName in fontFamilyNames {
    print("Font Family Name = [\(familyName)]")
    let names = UIFont.fontNamesForFamilyName(familyName as! String)
    print("Font Names = [\(names)")
    }
     aboutUsTextView.font = UIFont(name: "Lato-Light1.ttf", size: 30.0)
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
}