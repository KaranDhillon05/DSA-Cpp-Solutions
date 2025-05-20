/*
 * Day: 475 | Date: 2025-05-20
 * Q475: Design In-Memory File System
 * Difficulty: Hard
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class FileSystem {
    struct Node {
        bool isFile = false;
        string content;
        unordered_map<string, shared_ptr<Node>> children;
    };
    shared_ptr<Node> root = make_shared<Node>();
    shared_ptr<Node> getNode(const string& path) {
        if (path == "/") return root;
        auto cur = root;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (part.empty()) continue;
            if (!cur->children.count(part)) cur->children[part] = make_shared<Node>();
            cur = cur->children[part];
        }
        return cur;
    }
public:
    vector<string> ls(string path) {
        auto node = getNode(path);
        if (node->isFile) {
            size_t pos = path.find_last_of('/');
            return {path.substr(pos + 1)};
        }
        vector<string> res;
        for (auto& [name, _] : node->children) res.push_back(name);
        sort(res.begin(), res.end());
        return res;
    }
    void mkdir(string path) { getNode(path); }
    void addContentToFile(string filePath, string content) {
        auto node = getNode(filePath);
        node->isFile = true;
        node->content += content;
    }
    string readContentFromFile(string filePath) { return getNode(filePath)->content; }
};
