#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>
namespace pt = boost::property_tree;

#ifndef __STDYNSCHEMA_H__
#define __STDYNSCHEMA_H__


struct STDynSchema
{                      
    std::string m_model;                      
    std::set<std::string > m_shapes; 
    void load(const std::string &filename);
    void save(const std::string &filename);
};

#endif