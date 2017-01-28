//
//  NewWebsiteViewController.swift
//  iOU 4.0
//
//  Created by Dominick Hera on 1/29/15.
//  Copyright (c) 2015 Posa. All rights reserved.
//

import UIKit

class NewWebsiteViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let url = NSURL(string: "www.apple.com")
        let request = NSURLRequest(URL: url!)
        //webView.loadRequest(request)
       // let url = NSURL(string: "www.dominickhera.com")
        //let request = NSURLRequest(URL: url!)
        //newWebView.loadRequest(request)

        // Do any additional setup after loading the view.
    }
    @IBAction func openInSafari(sender: AnyObject) {
        var url : NSURL
        url = NSURL(string: "http://www.dominickhera.com")!
        UIApplication.sharedApplication().openURL(url)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}
