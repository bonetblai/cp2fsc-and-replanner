#ifndef OPTIONS_H
#define OPTIONS_H

#include <vector>

namespace Options {

  struct Option {
      std::string opt_;
      Option(const Option &option) : opt_(option.opt_) { }
      Option(const std::string &opt) : opt_(opt) { }
      bool match(const std::string &opt) const { return opt_ == opt; }
      bool operator==(const Option &opt) const {
          return opt_ == opt.opt_;
      }
      const Option & operator=(const Option &opt) {
          opt_ = opt.opt_;
          return *this;
      }
  };

  struct Mode {
      std::vector<Option> options_;
      std::vector<Option> enabled_;

      void add(const Option &opt) {
          if( !is_option(opt) )
              options_.push_back(opt);
      }
      void add(const std::string &opt) { add(Option(opt)); }

      bool is_option(const Option &opt) const {
          for( size_t i = 0; i < options_.size(); ++i ) {
              if( options_[i] == opt )
                  return true;
          }
          return false;
      }

      bool is_enabled(const Option &opt) const {
          for( size_t i = 0; i < enabled_.size(); ++i ) {
              if( enabled_[i] == opt )
                  return true;
          }
          return false;
      }
      bool is_enabled(const std::string &opt) const {
          return is_enabled(Option(opt));
      }

      bool enable(const Option &opt) {
          if( is_option(opt) ) {
              if( !is_enabled(opt) )
                  enabled_.push_back(opt);
              return true;
          } else
              return false;
      }
      bool enable(const std::string &opt) { return enable(Option(opt)); }

      bool clear(const Option &opt) {
          if( is_option(opt) ) {
              if( is_enabled(opt) ) {
                  for( size_t i = 0; i < enabled_.size(); ++i ) {
                      if( enabled_[i] == opt ) {
                          enabled_[i] = enabled_.back();
                          enabled_.pop_back();
                      }
                  }
              }
              return true;
          } else
              return false;
      }
      bool clear(const std::string &opt) { return clear(Option(opt)); }
  };

};

#endif
