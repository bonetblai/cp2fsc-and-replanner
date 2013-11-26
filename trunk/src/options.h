#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <vector>

namespace Options {

  struct Option {
      std::string name_;
      std::string desc_;
      Option(const Option &option) : name_(option.name_), desc_(option.desc_) { }
      Option(const std::string &name) : name_(name), desc_("") { }
      Option(const std::string &name, const std::string &desc) : name_(name), desc_(desc) { }
      const std::string& name() const { return name_; }
      const std::string& desc() const { return desc_; }
      bool match(const std::string &name) const { return name_ == name; }
      bool operator==(const Option &name) const {
          return name_ == name.name_;
      }
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
      std::vector<Option> options_;
      std::vector<Option> enabled_;

      void add(const Option &opt) {
          if( !is_option(opt) )
              options_.push_back(opt);
      }
      void add(const std::string &opt) { add(Option(opt)); }
      void add(const std::string &opt, const std::string &desc) { add(Option(opt, desc)); }

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

      void print(std::ostream &os) const {
          std::cout << "xxx=" << options_.size() << std::endl;
          for( size_t k = 0; k < options_.size(); ++k ) {
              std::cout << "option: " << options_[k] << " = "
                        << (is_enabled(options_[k]) ? "on" : "off")
                        << std::endl;
          }
      }
  };

};

#endif

