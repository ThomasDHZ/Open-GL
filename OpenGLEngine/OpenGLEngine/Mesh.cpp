#include "Mesh.h"



Mesh::Mesh(Vertex vertex, Shader shader, string DiffuseMapPath, string SpecularMapPath)
{
	ModelTexture = Texture(shader, DiffuseMapPath, SpecularMapPath);

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	Vertex vertices[] =
	{
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f,  0.0f, -1.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f, -0.5f), vec3(0.0f,  0.0f, -1.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f, -0.5f), vec3(0.0f,  0.0f, -1.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f, -0.5f), vec3(0.0f,  0.0f, -1.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f, -0.5f), vec3(0.0f,  0.0f, -1.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f,  0.0f, -1.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },

			 { vec3(-0.5f, -0.5f,  0.5f), vec3(0.0f,  0.0f, 1.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f,  0.5f), vec3(0.0f,  0.0f, 1.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f,  0.0f, 1.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f,  0.0f, 1.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f,  0.5f), vec3(0.0f,  0.0f, 1.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f,  0.5f), vec3(0.0f,  0.0f, 1.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },

			 { vec3(-0.5f,  0.5f,  0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f, -0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f,  0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f,  0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },

			 { vec3(0.5f,  0.5f,  0.5f), vec3(1.0f,  0.0f,  0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f, -0.5f), vec3(1.0f,  0.0f,  0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f, -0.5f), vec3(1.0f,  0.0f,  0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f, -0.5f), vec3(1.0f,  0.0f,  0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f,  0.5f), vec3(1.0f,  0.0f,  0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(1.0f,  0.0f,  0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },

			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, -1.0f,  0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f, -0.5f), vec3(0.0f, -1.0f,  0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f,  0.5f), vec3(0.0f, -1.0f,  0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f,  0.5f), vec3(0.0f, -1.0f,  0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f,  0.5f), vec3(0.0f, -1.0f,  0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, -1.0f,  0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },

			 { vec3(-0.5f,  0.5f, -0.5f), vec3(0.0f,  1.0f,  0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f, -0.5f), vec3(0.0f,  1.0f,  0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f,  1.0f,  0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f,  1.0f,  0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f,  0.5f), vec3(0.0f,  1.0f,  0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f, -0.5f), vec3(0.0f,  1.0f,  0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) }
	};
	Vertex vertices2[] = {
	 { vec3(0.5f,  0.5f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },  // top right
	 { vec3(0.5f, -0.5f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f)},
	 { vec3(-0.5f, -0.5f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
	 { vec3(-0.5f,  0.5f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) }
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(VertexMap::vPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(VertexMap::vPosition);

	glVertexAttribPointer(VertexMap::vNormalMapping, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(VertexMap::vNormalMapping);

	glVertexAttribPointer(VertexMap::vTextureCoordinates, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(VertexMap::vTextureCoordinates);

	glVertexAttribPointer(VertexMap::vTangant, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(VertexMap::vTangant);

	glVertexAttribPointer(VertexMap::vBitangant, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(11 * sizeof(float)));
	glEnableVertexAttribArray(VertexMap::vBitangant);

	glVertexAttribPointer(VertexMap::vColor, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(14 * sizeof(float)));
	glEnableVertexAttribArray(VertexMap::vColor);

	ModelMatrix = mat4(1.0f);
	Position = vec3(0.0f, 0.0f, 0.0f);
	Rotation = vec3(0.0f, 0.0f, 0.0f);
	Scale = vec3(1.0f);

	int VertexFloatCount = sizeof(Vertex)/sizeof(float);
	VertexCount = (sizeof(vertices) / VertexFloatCount) / sizeof(float);

}


Mesh::~Mesh()
{
}

void Mesh::Update(Shader shader)
{
	ModelTexture.Update(shader);

	glBindVertexArray(VAO);

	ModelMatrix = mat4(1.0f);
	ModelMatrix = translate(ModelMatrix, Position);
	ModelMatrix = rotate(ModelMatrix, radians(Rotation.x), vec3(1.0f, 0.0f, 0.0f));
	ModelMatrix = rotate(ModelMatrix, radians(Rotation.y), vec3(0.0f, 1.0f, 0.0f));
	ModelMatrix = rotate(ModelMatrix, radians(Rotation.z), vec3(0.0f, 0.0f, 1.0f));
	ModelMatrix = scale(ModelMatrix, Scale);

	shader.SetMat4("model", ModelMatrix);

	glDrawArrays(GL_TRIANGLES, 0, VertexCount);
}
void Mesh::DeleteBuffers()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
mat4 Mesh::GetModelMatrix()
{
	return ModelMatrix;
}
void Mesh::SetPosition(float x, float y, float z)
{
	Position = vec3(x, y, z);
}
void Mesh::SetPosition(vec3 position)
{
	Position = position;
}
void Mesh::SetRotation(float x, float y, float z)
{
	Rotation = vec3(x, y, z);
}
void Mesh::SetRotation(vec3 rotation)
{
	Rotation = rotation;
}
void Mesh::SetRotationX(float x)
{
	Rotation.x = x;
}
void Mesh::SetRotationY(float y)
{
	Rotation.y = y;
}
void Mesh::SetRotationZ(float z)
{
	Rotation.z = z;
}
void Mesh::SetScale(float x, float y, float z)
{
	Scale = vec3(x, y, z);
}
void Mesh::SetScale(vec3 scale)
{
	Scale = scale;
}
