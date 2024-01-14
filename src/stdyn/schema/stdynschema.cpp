#include <iostream>
#include "stdynschema.h"

struct STDynSchema stDynSchema;

void STDynSchema::load(const std::string &filename)
{
    pt::ptree tree;

    pt::read_xml(filename, tree);
    std::cout << tree.get<std::string>("model.name") << std::endl;
    m_model = tree.get<std::string>("model.name");

    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("model.shapes")) {
        m_shapes.insert(v.second.data());
    }
}

void STDynSchema::save(const std::string &filename)
{
    pt::ptree tree;
    tree.put("model.name", m_model);

    BOOST_FOREACH(const std::string &s, m_shapes)
        tree.add("model.shapes.shape", s);

    pt::write_xml(filename, tree);
}