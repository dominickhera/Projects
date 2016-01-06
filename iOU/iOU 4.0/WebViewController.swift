//
//  WebViewController.swift
//  iOU 4.0
//
//  Created by Dominick Hera on 2/24/15.
//  Copyright (c) 2015 Posa. All rights reserved.
//

import UIKit

class WebViewController: UIViewController {

    @IBOutlet weak var webView: UIWebView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let url = NSURL(string: "http://www.dominickhera.com")
        let request = NSURLRequest(URL: url!)
        webView.loadRequest(request)

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    @IBAction func goForwardButton(sender: AnyObject) {
        webView.goForward()
    }
    
    
    @IBAction func goBackButton(sender: AnyObject) {
        webView.goBack()
    }
    
    @IBAction func refreshButton(sender: AnyObject) {
        
        webView.reload()
    }
    @IBAction func safariButton(sender: AnyObject) {
        var url: NSURL
        url = NSURL(string: "https://www.dominickhera.com")!
        UIApplication.sharedApplication().openURL(url)
        
    }


}
