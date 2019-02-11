#pragma once
#include <stdinc.h>
using namespace std;

class Texture {
public:
    Texture(string path, int texSample = GL_REPEAT);
    ~Texture();

    GLuint tex;

    static inline shared_ptr<Texture> get(string name) {
        if (_textureCache.count(name) > 0) {
            return _textureCache[name];
        } else {
            return make_shared<Texture>(name);
        }
    };

private:
    static map<string, shared_ptr<Texture>> _textureCache;
}