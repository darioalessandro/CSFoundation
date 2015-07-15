//
//  MergeSort.swift
//  MergeSort
//
//  Created by Dario Lencina on 7/15/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

import Foundation

class MergeSort {
    
    class func mergeSort(chunkA : NSArray, chunkB : NSArray) -> NSArray {
        let sortedArraySize = chunkA.count + chunkB.count
        let sortedArray = NSMutableArray(capacity: sortedArraySize)
        
        var aPtr = 0
        var bPtr = 0
        
        for(var k = 0; k < sortedArraySize ; k++) {
            if(aPtr >= chunkA.count) {
                let t: AnyObject = chunkB[bPtr++]
                sortedArray.addObject(t)
            } else if(bPtr >= chunkB.count) {
                let t: AnyObject = chunkA[aPtr++]
                sortedArray.addObject(t)
            } else if((chunkA[aPtr] as! NSNumber).compare((chunkB[bPtr] as! NSNumber)).rawValue ==  -1) {
                let t: AnyObject = chunkA[aPtr++]
                sortedArray.addObject(t)
            } else {
                let t: AnyObject = chunkB[bPtr++]
                sortedArray.addObject(t)
            }
        }
        
        return sortedArray;
    }
    
    class func sort(a : NSArray) -> NSArray {
        if(a.count < 2) {
            return a
        }else{
            let chunkARange = NSMakeRange(0, a.count/2)
            let chunkBRange = NSMakeRange(chunkARange.length, a.count - chunkARange.length)
            
            let chunkA = sort(a.subarrayWithRange(chunkARange))
            let chunkB = sort(a.subarrayWithRange(chunkBRange))
            
            return self.mergeSort(chunkA, chunkB: chunkB)
        }
    }

}
