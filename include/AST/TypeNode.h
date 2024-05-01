#ifndef TYPENODE_H
#define TYPENODE_H

#pragma once

#include "ASTNode.h"
#include "ASTValueType.h"
#include "../Lexer.h"

#include <optional>

namespace AST 
{
    class TypeNode : public Node
    {
    public:
        ValueType type;
        std::optional<TokenReference> type_token;

        TypeNode(ValueType type, TokenReference type_token)
            : type(type), type_token(type_token)
        {};
        TypeNode(ValueType type)
            : type(type)
        {};
        ~TypeNode() {};

        static constexpr NodeType node_type = NodeType::n_type;

        const std::string node_description() override {
            return "type<" + type.get_type_desciption() + ">";
        }

    private:

    };
};


#endif