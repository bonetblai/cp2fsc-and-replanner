#ifndef NAME_H
#define NAME_H

#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

class Name {
  public:
    static bool domain_name_only;
    static bool problem_name_only;

    virtual ~Name() { }
    virtual void write(std::ostream &os, bool cat) const = 0;

    std::string to_string() const {
        std::ostringstream s;
        write(s, true);
        return s.str();
    }
    bool equals(const Name *name) const { return to_string() == name->to_string(); }
};

class name_vec : public std::vector<const Name*> { };

inline std::ostream& operator<<(std::ostream &os, const Name &n) {
    n.write(os, false);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const Name *n) {
    n->write(os, false);
    return os;
}

class StringName : public Name {
    const char* _string;
  public:
    StringName(const char *s) : _string(s) { }
    virtual ~StringName() { }
    virtual void write(std::ostream &os, bool cat) const { os << _string; }
};

class CopyName : public Name {
    char *_string;
  public:
    CopyName(const char *s) : _string(strdup(s)) { }
    CopyName(const std::string &s) : _string(strdup(s.c_str())) { }
    virtual ~CopyName() { delete _string; }
    virtual void write(std::ostream &os, bool cat) const { os << _string; }
};

#endif

