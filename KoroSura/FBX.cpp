#include "FBX.h"
#include"DirectGraphics.h"

FBXLoader* FBXLoader::FBXpInstance = nullptr;

void FBXLoader::CreateFBXInstance() {
	if (FBXpInstance == nullptr) {
		FBXpInstance = new FBXLoader();
	}
}
FBXLoader& FBXLoader::GetInstance() {
	if (FBXpInstance == nullptr) {
		MessageBox(0, "FBX�̃C���X�^���X����������Ă��܂���", "", MB_OK);
	}
	return *FBXpInstance;
}

void FBXLoader::GetTextureNames(
	FbxSurfaceLambert* lambert,
	const FbxProperty& prop,
	ModelDataFBX* pMeshData)
{
	//FbxLayeredTexture �̐����擾
	int layeredTextureCount = prop.GetSrcObjectCount<FbxLayeredTexture>();

	//�A�^�b�`���ꂽ�e�N�X�`���� FbxLayeredTexture �̏ꍇ
	if (0 < layeredTextureCount) {

		//�A�^�b�`���ꂽ�e�N�X�`���̐������J��Ԃ�
		for (int i = 0; i < layeredTextureCount; ++i) {

			//�e�N�X�`�����擾
			FbxLayeredTexture* layeredTexture = prop.GetSrcObject<FbxLayeredTexture>(i);

			//���C���[�����擾
			int layerNum = prop.GetSrcObjectCount<fbxsdk::FbxLayeredTexture>();
			//int textureCount = layeredTexture - &gtGetSrcObjectCount<FbxFileTexture>();

			//���C���[�������J��Ԃ�
			for (int j = 0; j < layerNum; ++j) {

				//�e�N�X�`�����擾
				FbxFileTexture* texture = prop.GetSrcObject<FbxFileTexture>(j);

				if (texture) {

					//�e�N�X�`�������擾
					UserTexture tmp;
					tmp.TextureName = texture->GetRelativeFileName();

					//UVSet�����擾
					std::string UVSetName = texture->UVSet.Get().Buffer();

					//UVSet�����r���Ή����Ă���e�N�X�`���Ȃ�ێ�
					for (int k = 0; k < pMeshData->uvSetName.size(); ++k) {
						if (pMeshData->uvSetName[k] == UVSetName) {
							if (FAILED(D3DXCreateTextureFromFile(
								(*DirectGraphics::GetInstance().GetDevice()),
								tmp.TextureName.c_str(),
								&tmp.pTexture))) {
								tmp.pTexture = NULL;
							}
							pMeshData->textures.push_back(tmp);
							break;
						}
					}
				}
			}
		}
	}
	else {
		//�e�N�X�`�������擾
		int fileTextureCount = prop.GetSrcObjectCount<FbxFileTexture>();

		if (0 < fileTextureCount) {

			//�e�N�X�`���̐������J��Ԃ�
			for (int j = 0; fileTextureCount > j; j++) {

				//�e�N�X�`�����擾
				FbxFileTexture* texture = prop.GetSrcObject<FbxFileTexture>(j);

				if (texture) {

					//�e�N�X�`�������擾

					UserTexture tmp;
					tmp.TextureName = texture->GetRelativeFileName();

					//UVSet�����擾
					std::string UVSetName = texture->UVSet.Get().Buffer();

					//UVSet�����r���Ή����Ă���e�N�X�`���Ȃ�ێ�
					for (int k = 0; k < pMeshData->uvSetName.size(); ++k) {
						std::string textureName = "FBX\\FBXTexture\\" + tmp.TextureName;
						if (pMeshData->uvSetName[k] == UVSetName) {
							if (FAILED (D3DXCreateTextureFromFile(
								(*DirectGraphics::GetInstance().GetDevice()),
								textureName.c_str(),
								&tmp.pTexture))){
								tmp.pTexture = NULL;
							}
							pMeshData->textures.push_back(tmp);
							break;
						}
					}
				}
			}
		}
	}
}

void FBXLoader::GetTexture(FbxMesh* pMesh, ModelDataFBX* pMeshData)
{
	//�m�[�h�̎擾
	FbxNode* node = pMesh->GetNode();
	if (node == 0) {
		return;
	}

	// �}�e���A���̐�
	pMeshData->MaterialCount = node->GetMaterialCount();
	if (pMeshData->MaterialCount == 0) {
		return;
	}

	//�}�e���A�����J��Ԃ�
	for (int i = 0; i < pMeshData->MaterialCount; ++i) {

		// �}�e���A�������擾
		FbxSurfaceMaterial* material = node->GetMaterial(i);

		if (material != 0) {

			// Lambert��Phong��(Lambert�̂ݑΉ�)
			if (material->GetClassId().Is(FbxSurfaceLambert::ClassId)) {

				// Lambert�Ƀ_�E���L���X�g
				FbxSurfaceLambert* lambert = (FbxSurfaceLambert*)material;

				// �A���r�G���g
				FbxProperty property = lambert->FindProperty(FbxSurfaceMaterial::sAmbient);
				pMeshData->Ambient.red = (float)lambert->Ambient.Get().mData[0];
				pMeshData->Ambient.green = (float)lambert->Ambient.Get().mData[1];
				pMeshData->Ambient.blue = (float)lambert->Ambient.Get().mData[2];
				GetTextureNames(lambert, property, pMeshData);

				// �f�B�t���[�Y
				pMeshData->Diffuse.red = (float)lambert->Diffuse.Get().mData[0];
				pMeshData->Diffuse.green = (float)lambert->Diffuse.Get().mData[1];
				pMeshData->Diffuse.blue = (float)lambert->Diffuse.Get().mData[2];
				property = lambert->FindProperty(FbxSurfaceMaterial::sDiffuse);
				GetTextureNames(lambert, property, pMeshData);

				// �G�~�b�V�u
				/*pMeshData->Emissive.red = (float)lambert->Emissive.Get().mData[0];
				pMeshData->Emissive.green = (float)lambert->Emissive.Get().mData[1];
				pMeshData->Emissive.blue = (float)lambert->Emissive.Get().mData[2];
				property = lambert->FindProperty(FbxSurfaceMaterial::sEmissive);
				GetTextureNames(lambert, property, pMeshData);*/

				//// �o���v
				//bump_.x = (float)lambert->GetBump().Get()[0];
				//bump_.y = (float)lambert->GetBump().Get()[1];
				//bump_.z = (float)lambert->GetBump().Get()[2];

				// ���ߓx
				//pMeshData->Transparency = (float)lambert->TransparentColor.Get().mData[0];

			}
			else if (material->GetClassId().Is(FbxSurfacePhong::ClassId)) {

				// Phong�Ƀ_�E���L���X�g
				FbxSurfacePhong* phong = (FbxSurfacePhong*)material;
			}


		}
	}
}

void FBXLoader::GetVertexUV(FbxMesh* pMesh, ModelDataFBX* pMeshData)
{
	int UVLayerCount = pMesh->GetElementUVCount();

	for (int i = 0; UVLayerCount > i; i++) {

		//UV�o�b�t�@���擾
		FbxGeometryElementUV* UV = pMesh->GetElementUV(i);

		//�}�b�s���O���[�h�̎擾
		FbxGeometryElement::EMappingMode mapping = UV->GetMappingMode();

		//���t�@�����X���[�h�̎擾
		FbxGeometryElement::EReferenceMode reference = UV->GetReferenceMode();

		//UV�����擾
		int uvCount = UV->GetDirectArray().GetCount();

		//�}�b�s���O���[�h�̔���
		switch (mapping) {
		case FbxGeometryElement::eByControlPoint:
			break;

		case FbxGeometryElement::eByPolygonVertex:
			//���t�@�����X���[�h�̔���
			switch (reference) {
			case FbxGeometryElement::eDirect:
				break;

			case FbxGeometryElement::eIndexToDirect:
			{
				FbxLayerElementArrayTemplate<int>* uvIndex = &UV->GetIndexArray();
				int uvIndexCount = uvIndex->GetCount();

				//UV��ێ�
				D3DXVECTOR2 temp;
				for (int j = 0; j < uvIndexCount; ++j) {

					temp.x = (float)UV->GetDirectArray().GetAt(uvIndex->GetAt(j))[0];

					temp.y = 1.0f - (float)UV->GetDirectArray().GetAt(uvIndex->GetAt(j))[1];

					pMeshData->uvBuffer.push_back(temp);
				}

				//UVSet�����擾
				pMeshData->uvSetName.push_back(UV->GetName());
			}
			break;

			default:
				break;
			}
			break;

		case FbxGeometryElement::eByEdge:
			break;

		case FbxGeometryElement::eByPolygon:
			break;

		default:
			break;
		}
	}
}

void FBXLoader::GetVertexNormal(FbxMesh* pMesh, ModelDataFBX* pMeshData)
{
	int normalLayerCount = pMesh->GetElementNormalCount();

	for (int i = 0; normalLayerCount > i; i++) {

		//�@���Z�b�g�̎擾
		FbxGeometryElementNormal* normal = pMesh->GetElementNormal(i);
		//�}�b�s���O���[�h�̎擾
		FbxGeometryElement::EMappingMode mapping = normal->GetMappingMode();
		//���t�@�����X���[�h�̎擾
		FbxGeometryElement::EReferenceMode reference = normal->GetReferenceMode();

		//�}�b�s���O���[�h�̔���
		switch (mapping) {
		case FbxGeometryElement::eByControlPoint:

			//���t�@�����X���[�h�̔���
			switch (reference) {
			case FbxGeometryElement::eDirect:

				//�@�������擾
				int normalCount = normal->GetDirectArray().GetCount();

				//-----------------------------------------------------------------------
				// eDirect �̏ꍇ�f�[�^�͏��ԂɊi�[����Ă���̂ł��̂܂ܕێ�
				//-----------------------------------------------------------------------

				for (int i = 0; normalCount > i; i++) {
					//�@���̎擾 
					pMeshData->NormalVector.push_back(new D3DXVECTOR3);
					pMeshData->NormalVector[i]->x = (float)normal->GetDirectArray().GetAt(i)[0];
					pMeshData->NormalVector[i]->y = (float)normal->GetDirectArray().GetAt(i)[1];
					pMeshData->NormalVector[i]->z = (float)normal->GetDirectArray().GetAt(i)[2];
				}
				break;

				//case FbxGeometryElement::eIndexToDirect:
				//	break;
			}
			break;

		case FbxGeometryElement::eByPolygonVertex:
			switch (reference) {
			case FbxGeometryElement::eDirect:
				//�@�������擾
				int normalCount = normal->GetDirectArray().GetCount();

				for (int i = 0; normalCount > i; i++) {
					//�@���̎擾 
					pMeshData->NormalVector.push_back(new D3DXVECTOR3);
					pMeshData->NormalVector[i]->x = (float)normal->GetDirectArray().GetAt(i)[0];
					pMeshData->NormalVector[i]->y = (float)normal->GetDirectArray().GetAt(i)[1];
					pMeshData->NormalVector[i]->z = (float)normal->GetDirectArray().GetAt(i)[2];
				}
				break;
			}
		default:
			break;
		}
	}
}

void FBXLoader::GetPosition(FbxMesh* pMesh, ModelDataFBX* pMeshData)
{
	//���|���S�����̎擾
	pMeshData->PolygonNum = pMesh->GetPolygonCount();

	//�|���S�����_�C���f�b�N�X���̎擾
	pMeshData->PolygonVertexNum = pMesh->GetPolygonVertexCount();

	// ���_��
	pMeshData->controlNum = pMesh->GetControlPointsCount();

	// ���_���W�z��
	FbxVector4* src = pMesh->GetControlPoints();

	// �R�s�[
	pMeshData->Positions = new D3DXVECTOR4[pMeshData->controlNum];

	for (int i = 0; i < pMeshData->controlNum; ++i) {
		pMeshData->Positions[i].x = src[i][0];
		pMeshData->Positions[i].y = src[i][1];
		pMeshData->Positions[i].z = src[i][2];
		pMeshData->Positions[i].w = src[i][3];
	}

	//�|���S�����_�C���f�b�N�X�z��̎擾
	pMeshData->IndexAry = pMesh->GetPolygonVertices();
	pMeshData->IndexAry = new int [pMeshData->PolygonVertexNum];
	memcpy(pMeshData->IndexAry, pMesh->GetPolygonVertices(), sizeof(int) * pMeshData->PolygonVertexNum);

	//���|���S������
	for (int p = 0; p < pMeshData->PolygonNum; p++) {

		//p�Ԗڂ̃|���S���̒��_��
		int IndexNumInPolygon = pMesh->GetPolygonSize(p);

		for (int n = 0; n < IndexNumInPolygon; n++) {

			// �|���S��p���\������n�Ԗڂ̒��_�̃C���f�b�N�X�ԍ�
			int IndexNumber = pMesh->GetPolygonVertex(p, n);
		}
	}
}

void FBXLoader::GetMesh(FbxNode* node, ModelDataFBX* pMeshData) {

	//--- �m�[�h�̑������擾 ---//
	FbxNodeAttribute* attr = node->GetNodeAttribute();

	if (nullptr != attr) {

		//--- �����̔��� ---//
		switch (attr->GetAttributeType()) {

			//--- ���b�V���m�[�h���� ---//
		case FbxNodeAttribute::eMesh:
			//���b�V���̎擾
			FbxMesh* pMesh = node->GetMesh();
			GetPosition(pMesh, pMeshData);
			GetVertexNormal(pMesh, pMeshData);
			GetVertexUV(pMesh, pMeshData);
			GetTexture(pMesh, pMeshData);

			break;
		}
	}

	//--- �q�m�[�h�̍ċA�T�� ---//
	int childCount = node->GetChildCount();
	for (int i = 0; i < childCount; i++) {
		GetMesh(node->GetChild(i), pMeshData);
	}
}

void FBXLoader::FBXLoad(ModelDataFBX* pMeshData, char* filePath) {

	FbxManager* manager = NULL;
	FbxScene* scene = NULL;

	manager = FbxManager::Create();

	if (NULL != manager) {

		//�C���|�[�^�̍쐬
		FbxImporter* importer = FbxImporter::Create(manager, "");

		if (nullptr != importer) {

			//�V�[���̍쐬�i�󂯎��l)
			scene = FbxScene::Create(manager, "");

			if (nullptr != scene) {

				//�C���|�[�^�̏�����
				bool result = importer->Initialize(filePath);

				if (result) {

					//�C���|�[�g�I
					result = importer->Import(scene);
					FbxGeometryConverter GeometryConverter(manager);
					GeometryConverter.Triangulate(scene, true);
					std::cout << "���������I" << std::endl;
				}
			}
		}

		//�C���|�[�^�̍폜
		importer->Destroy();

		//���[�g�m�[�h���擾
		FbxNode* rootNode = scene->GetRootNode();

		if (nullptr != rootNode) {
			//���[�g�m�[�h�̎q�m�[�h�����擾
			int childCount = rootNode->GetChildCount();

			//�q�m�[�h�̐������T��������
			for (int i = 0; childCount > i; i++) {
				GetMesh(rootNode->GetChild(i), pMeshData);
			}
		}

		manager->Destroy();
	}
}