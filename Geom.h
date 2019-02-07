#pragma once
#include <stdinc.h>
#include "Shader.h"
using namespace std;

class Geom {
public:
  Geom(vector<float> vertices, vector<unsigned int> elements);
  ~Geom();

  vector<float> vertexes;
  vector<unsigned int> elements;

  GLuint vao;
  GLuint vbo;
  GLuint ebo;

  shared_ptr<Shader> shader;
  // Shader shader;
  GLint drawType = GL_STATIC_DRAW;

  void bufferElements();
  void bufferVertexes();
  void bufferVertexPosition();
  
  void draw();

  void setMaterialCallback(std::function<void(shared_ptr<Shader>)> matcb) {
    materialCallback = matcb;
    materialCallbackSet = true;
  };

private:
  void init();

  void callMaterial() {
    if (!materialCallbackSet) return;

    materialCallback(shader);
  };
  
  bool materialCallbackSet = false;
  std::function<void(shared_ptr<Shader>)> materialCallback;
};
