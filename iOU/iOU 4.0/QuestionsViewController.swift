//
//  QuestionsViewController.swift
//  iOU 4.0
//
//  Created by Dominick Hera on 2/27/15.
//  Copyright (c) 2015 Posa. All rights reserved.
//

import UIKit

class QuestionsViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func shareThisApp(sender: AnyObject) {
    
    let sc = UIActivityViewController(activityItems: ["You should check out this cool app called iOU. It's perfect for keeping track of loans. You can find the app at http://goo.gl/pn3Lm9"], applicationActivities: nil)
    self.presentViewController(sc, animated: true, completion: nil)
    
}

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
