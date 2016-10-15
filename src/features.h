/*
 *  Copyright (C) 2011 - <date> Blai Bonet, Universidad Simon Bolivar
 * 
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 *  Blai Bonet, bonet@ldc.usb.ve, bonetblai@gmail.com
 *
 */

#ifndef FEATURES_H
#define FEATURES_H

#include <cassert>
#include <iostream>
#include <list>
#include <set>

namespace Width {

  class Feature {
    public:
      Feature() { }
      virtual ~Feature() { }
      virtual void print(std::ostream &os) const = 0;
  };

  class FeatureList : public std::list<const Feature*> {
  };

  class FeatureSet : public std::set<const Feature*> {
    public:
      FeatureSet() { }
      FeatureSet(const std::set<const Feature*> &features)
        : std::set<const Feature*>(features) {
      }
  };

} // namespace Width

#endif

