#ifndef OPTIONS_H
#define OPTIONS_H

#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include "utils.h"

namespace Options {

  struct Option {
      std::string name_;
      std::string desc_;
      Option(const Option &opt) : name_(opt.name_), desc_(opt.desc_) { }
      Option(const std::string &name) : name_(name), desc_("") { }
      Option(const std::string &name, const std::string &desc) : name_(name), desc_(desc) { }
      const std::string& name() const { return name_; }
      const std::string& desc() const { return desc_; }
      bool match(const std::string &name) const { return name_ == name; }
      bool operator==(const Option &opt) const { return name_ == opt.name_; }
      bool operator<(const Option &opt) const { return name_ < opt.name_; }
      const Option & operator=(const Option &opt) {
          name_ = opt.name_;
          desc_ = opt.desc_;
          return *this;
      }
      void print(std::ostream &os) const { os << name_; }
  };

  inline std::ostream& operator<<(std::ostream &os, const Option &opt) {
      opt.print(os);
      return os;
  }

  struct Mode {
      std::set<Option> options_;
      std::set<Option> enabled_;

      void add(const Option &opt) { options_.insert(opt); }
      void add(const std::string &opt) { add(Option(opt)); }
      void add(const std::string &opt, const std::string &desc) { add(Option(opt, desc)); }

      bool is_option(const std::string &opt) const { return is_option(Option(opt)); }
      bool is_enabled(const std::string &opt) const { return is_enabled(Option(opt)); }
      bool is_option(const Option &opt) const { return options_.find(opt) != options_.end(); }
      bool is_enabled(const Option &opt) const {
          if( !is_option(opt) ) {
              std::cout << Utils::internal_error() << "checking for inexistent option '" << opt.name_ << "'" << std::endl;
              return false;
          }
          return enabled_.find(opt) != enabled_.end();
      }

      bool enable(const Option &opt) {
          bool good_option = is_option(opt);
          if( good_option ) enabled_.insert(opt);
          return good_option;
      }
      bool enable(const std::string &opt) { return enable(Option(opt)); }

      bool disable(const Option &opt) {
          bool good_option = is_option(opt);
          if( good_option ) enabled_.erase(opt);
          return good_option;
      }
      bool disable(const std::string &opt) { return disable(Option(opt)); }

      void print(std::ostream &os) const {
          //std::cout << "xxx=" << options_.size() << std::endl;
          for( std::set<Option>::const_iterator it = options_.begin(); it != options_.end(); ++it ) {
              std::cout << "option: " << *it << " = "
                        << (is_enabled(*it) ? "on" : "off")
                        << std::endl;
          }
      }

      struct const_iterator : public std::set<Option>::const_iterator {
          const_iterator(const std::set<Option>::const_iterator &it) : std::set<Option>::const_iterator(it) { }
      };
      const_iterator begin() const { return options_.begin(); }
      const_iterator end() const { return options_.end(); }
  };

  inline void parse_options(Mode &options, const char *options_str) {
      char *opts = strdup(options_str);
      char *opt = strtok(opts, ",");
      while( opt != 0 ) {
          bool good_option = true;
          if( opt[0] == '-' )
              good_option = options.disable(&opt[1]);
          else
              good_option = options.enable(opt[0] == '+' ? &opt[1] : opt);

          if( !good_option )
              std::cout << Utils::warning() << "unrecognized option '" << opt << "' (ignored)." << std::endl;
          opt = strtok(0, ",");
      }
      free(opts);
  }

};

#endif

