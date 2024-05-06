#ifndef ASTFILE_H
#define ASTFILE_H

#pragma once

#include <filesystem>
#include <string>
#include <optional>

#include "../Token.h"
#include "ScopeNode.h"

namespace AST
{  
    class Module;

    class File
    {
        const std::filesystem::path _path;

        // instead of storing to the content line by line for easy access
        // we will store a offset to the start of each line in the content
        std::vector<size_t> _line_offsets;

    public:

        Module *module = nullptr;

        ScopeNode *root = nullptr;

        // the plain text content of the file
        std::optional<std::string> content;

        
        File(
            const std::filesystem::path &path
        ) : 
            _path(path)
        {};
        ~File() {};

        const std::filesystem::path &get_path() const {
            return _path;
        }

        // sets the content of the file
        // this will also invalidate the line_offsets
        void set_content(const std::string &content);

        // will read the file from disk and update the content
        void read_from_disk();

        std::string debug_description() const;
        
        std::string get_content_of_line(uint32_t line) const;
    };

    struct TokenizedFile
    {
        const File *file;
        const TokenCollection::Slice token_slice;
    };
};
#endif