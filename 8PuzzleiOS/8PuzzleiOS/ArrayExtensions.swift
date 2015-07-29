//
//  ArrayExtensions.swift
//  8PuzzleiOS
//
//  Created by Dario Lencina on 7/28/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

import Foundation

extension Array {
    
    func forEach(iterator: (T) -> Void) -> Array {
        for item in self {
            iterator(item)
        }
        
        return self;
    }
    
}