//==============================================================
// �萔
float4x4 World;
float4x4 View;
float4x4 Proj;
float4 Diffuse;
float4 Ambient;
float3 Light;
texture MeshTex;

// �e�N�X�`���T���v��
sampler MeshSmp=sampler_state {
	Texture=<MeshTex>;
	MipFilter=LINEAR;
	MinFilter=LINEAR;
	MagFilter=LINEAR;
};

// ���_�V�F�[�_
void BasicVS (
	float4 in_pos : POSITION,
	float3 in_normal : NORMAL,
	float2 in_mesh_uv : TEXCOORD0,
	out float4 out_pos : POSITION,
	out float4 out_col : COLOR0,
	out float2 out_mesh_uv : TEXCOORD0
) {
	// ���_���W�A�e�N�X�`�����W
	out_pos = mul(in_pos, Proj);
	out_mesh_uv = in_mesh_uv;

	// ���_�F
	float3 normal = normalize(mul(in_normal, (float3x3)World));
	out_col = max(0, dot(normal, -Light)) + Ambient;
}

// �s�N�Z���V�F�[�_
float4 BasicPS(
	float2 in_mesh_uv : TEXCOORD0
) : COLOR {

	// �e�N�X�`���F�ƒ��_�F�̍���
	return tex2D(MeshSmp, in_mesh_uv) * Diffuse;
}

//==============================================================
// �e�N�j�b�N
technique Basic {
	pass P0 {
		VertexShader=compile vs_2_0 BasicVS();
		PixelShader=compile ps_2_0 BasicPS();
	}
}
