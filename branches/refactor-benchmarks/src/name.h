#ifndef NAME_H
#define NAME_H

#include <stdlib.h>
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
    virtual std::string to_string(bool cat = false) const = 0;

    void write(std::ostream &os, bool cat) const { os << to_string(cat); }
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
    const char *_string;
  public:
    StringName(const char *s) : _string(s) { }
    virtual ~StringName() { }
    virtual std::string to_string(bool cat = false) const { return std::string(_string); }
};

class CopyName : public Name {
    char *_string;
  public:
    CopyName(const char *s) : _string(strdup(s)) { }
    CopyName(const std::string &s) : _string(strdup(s.c_str())) { }
    virtual ~CopyName() { free(_string); }
    virtual std::string to_string(bool cat = false) const { return std::string(_string); }
};

class InstanceName : public Name {
    const char* domain_name;
    const char* problem_name;
  public:
    InstanceName(const char *d, const char *p) : domain_name(strdup(d)), problem_name(strdup(p)) { }
    InstanceName(const InstanceName &name) : domain_name(strdup(name.domain_name)), problem_name(strdup(name.problem_name)) { }
    virtual ~InstanceName() { free((char*)domain_name); free((char*)problem_name); }
    virtual std::string to_string(bool cat = false) const {
        if( domain_name_only )
            return std::string(domain_name);
        else if( problem_name_only )
            return std::string(problem_name);
        else
            return std::string(domain_name) + "::" + problem_name;
    }
};

#endif

