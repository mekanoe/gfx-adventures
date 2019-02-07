#pragma once
#include <stdinc.h>
using namespace std;

class Shader {
public:
  Shader();
  ~Shader();

  GLuint program;
  string name;

  void loadFiles(vector<string> files);
  void loadFile(string file);
  void loadString(string shaderCode, int type);
  void link();
  void use();
  void reset();
  void set(string uniformName, glm::vec4 v4);
  void set(string uniformName, glm::vec3 v3);
  void set(string uniformName, float f);

  GLint uniform(string uniformName);

  void updateUniformTime(map<string, glm::vec4> times);

  inline static shared_ptr<Shader> get(string name) { return shaders[name]; }

  inline static map<string, shared_ptr<Shader>> shaders;
  bool linked = false;

  static void preprocessGLSL(string *code);
  static void
  updateAllUniformTimes(chrono::time_point<chrono::high_resolution_clock> start,
                        chrono::time_point<chrono::high_resolution_clock> cur);

private:
  vector<GLuint> parts;
  map<string, GLint> uniforms;
};