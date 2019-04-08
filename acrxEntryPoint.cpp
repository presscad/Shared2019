// (C) Copyright 2002-2012 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CArxProject2App : public AcRxArxApp {

public:
	CArxProject2App () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		// TODO: Add your initialization code here

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}
	
	// The ACED_ARXCOMMAND_ENTRY_AUTO macro can be applied to any static member 
	// function of the CArxProject2App class.
	// The function should take no arguments and return nothing.
	//
	// NOTE: ACED_ARXCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid and
	// have arguments to define context and command mechanism.
	
	// ACED_ARXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext)
	// ACED_ARXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext)
	// only differs that it creates a localized name using a string in the resource file
	//   locCmdId - resource ID for localized command

	// Modal Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, MyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL)
	static void MyGroupMyCommand () {
		// Put your command code here

	}

	// Modal Command with pickfirst selection
	// ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, MyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET)
	static void MyGroupMyPickFirst () {
		ads_name result ;
		int iRet =acedSSGet (ACRX_T("_I"), NULL, NULL, NULL, result) ;
		if ( iRet == RTNORM )
		{
			// There are selected entities
			// Put your command using pickfirst set code here
		}
		else
		{
			// There are no selected entities
			// Put your command code here
		}
	}

	// Application Session Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, MyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION)
	static void MyGroupMySessionCmd () {
		// Put your command code here
	}

	// The ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO macros can be applied to any static member 
	// function of the CArxProject2App class.
	// The function may or may not take arguments and have to return RTNORM, RTERROR, RTCAN, RTFAIL, RTREJ to AutoCAD, but use
	// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal to return
	// a value to the Lisp interpreter.
	//
	// NOTE: ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid.
	
	//- ACED_ADSFUNCTION_ENTRY_AUTO(classname, name, regFunc) - this example
	//- ACED_ADSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file
	//- ACED_ADSCOMMAND_ENTRY_AUTO(classname, name, regFunc) - a Lisp command (prefix C:)
	//- ACED_ADSCOMMAND_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file

	// Lisp Function is similar to ARX Command but it creates a lisp 
	// callable function. Many return types are supported not just string
	// or integer.
	// ACED_ADSFUNCTION_ENTRY_AUTO(CArxProject2App, MyLispFunction, false)
	static int ads_MyLispFunction () {
		//struct resbuf *args =acedGetArgs () ;
		
		// Put your command code here

		//acutRelRb (args) ;
		
		// Return a value to the AutoCAD Lisp Interpreter
		// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal

		return (RTNORM) ;
	}

	static void MyGroupMyCommand1()
	{
		AcDbBlockTable *pBlkTbl;
		acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlkTbl, AcDb::kForWrite);
		// ���ģ�Ϳռ�Ŀ���¼
		AcDbBlockTableRecord *pBlkTblRcd;
		pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRcd,AcDb::kForWrite);

		AcDbTable* pTable = new AcDbTable;

		AcDbDictionary *pDict = NULL;
		AcDbObjectId idTblStyle;
		acdbHostApplicationServices()->workingDatabase()->getTableStyleDictionary(pDict,AcDb::kForRead);
		pDict->getAt(_T("Standard"),idTblStyle);
		pDict->close();

		pTable->setTableStyle(idTblStyle);


		AcDbTextStyleTable* pTextStyle = NULL;
		acdbHostApplicationServices()->workingDatabase()->getTextStyleTable(pTextStyle,AcDb::kForRead);
		AcDbObjectId textID;
		pTextStyle->getAt(_T("Standard"),textID);
		pTextStyle->close();

		if (!textID.isNull())
		{
		pTable->setTextStyle(textID);
		}



		pTable->setNumColumns(2);
		pTable->setNumRows(4);

		
		pTable->suppressHeaderRow(false);//���ñ���


										//��������
		pTable->setPosition(AcGePoint3d(100,100, 0));

		//�����и�
		pTable->setRowHeight(0,30);
		pTable->setRowHeight(1,5);
		pTable->setRowHeight(2,5);
		pTable->setRowHeight(3,5);

		//�����п�
		pTable->setColumnWidth(0,45);
		pTable->setColumnWidth(1,40);

		pTable->setTextString(1,1,_T("sfsfsdfsd"));
		pTable->setAutoScale(1,1,true);




		pTable->generateLayout();

		AcDbObjectId tableId;
		pBlkTblRcd->appendAcDbEntity(tableId,pTable);

		//pTable->setRegen();//Help�ļ���ʾ�ڲ�ʹ��,ʹ�ú��޷���ȷ��ʾ���

		AcDbVoidPtrArray entitySet;
		;

		if (pTable->explode(entitySet) == Acad::eOk)
		{
			for (int i = 0; i < entitySet.length(); i++)
			{

				AcDbEntity *pExpEnt = (AcDbEntity*)entitySet[i];
				//acutPrintf(_T("\n�ֽ��Ķ�����������: %s"), (pExpEnt->isA()->name()));
				AfxMessageBox((pExpEnt->isA()->name()));
				Acad::ErrorStatus es = pBlkTblRcd->appendAcDbEntity(pExpEnt);//��ը����ʵ����ӵ�ģ�Ϳռ���
				if (Acad::eOk == es)
				{
					pExpEnt->close();
				}
				//pEnty->close();
			}
			pTable->erase(true);
		}
		else
		{
			acutPrintf(_T("\n�ö����ܱ��ֽ⣡"));
		}

		pTable->close();
		pBlkTblRcd->close();
		pBlkTbl->close();

		//�ƶ�����
		//AcGePoint3d ptStart(0, 0, 0);
		//AcGePoint3d ptEnd(150, 150, 0);
		//Move(tableId, ptStart, ptEnd);

		//ˢ����Ļ
		actrTransactionManager->flushGraphics(); /*refresh screen*/
		acedUpdateDisplay();

		//AcDbDatabase* pCurDb = acdbHostApplicationServices()->workingDatabase();//��ȡ��ǰdwg
		//pCurDb->saveAs(L"d:\\5.dwg");//dwg���Ϊ




		//for (int i = 0; i < entitySet.length(); i++)
		//{
		//	AcDbEntity* pEnty = (AcDbEntity*)entitySet.at(i);
		//	if (pEnty != NULL)
		//	{
		//		pBlkTblRcd->appendAcDbEntity(pEnty);//��ը����ʵ����ӵ�ģ�Ϳռ���
		//		pEnty->close();
		//	}
		//}



		//delete pCurDb;
	}
	//static void MyGroupMyInsert()
	//{
	//	// ����û�����Ŀ鶨������
	//	char blkName[40]="D:\\5.dwg";
	//	//if (acedGetString(Adesk::kFalse, L"\n����ͼ������ƣ�", blkName) !=RTNORM)
	//	//{
	//	//	return;
	//	//}
	//	// ��õ�ǰ���ݿ�Ŀ��
	//	AcDbBlockTable *pBlkTbl;
	//	acdbHostApplicationServices()->workingDatabase()
	//		->getBlockTable(pBlkTbl, AcDb::kForWrite);
	//	// �����û�ָ���Ŀ鶨���Ƿ����
	//	CString strBlkDef;
	//	strBlkDef.Format(L"%s", blkName);
	//	//if (!pBlkTbl->has(strBlkDef))
	//	//{
	//	//	acutPrintf(L"\n��ǰͼ����δ����ָ�����ƵĿ鶨�壡");
	//	//	pBlkTbl->close();
	//	//	return;
	//	//}
	//	// ����û�����Ŀ���յĲ����
	//	ads_point pt;
	//	if (acedGetPoint(NULL, L"\n�������յĲ���㣺", pt) != RTNORM)
	//	{
	//		pBlkTbl->close();
	//		return;
	//	}
	//	AcGePoint3d ptInsert = asPnt3d(pt);
	//	//AcGePoint3d ptInsert(0, 0, 0);
	//	// ����û�ָ���Ŀ���¼
	//	AcDbObjectId blkDefId;
	//	pBlkTbl->getAt(strBlkDef, blkDefId);
	//	// ��������ն���
	//	AcDbBlockReference *pBlkRef = new AcDbBlockReference(ptInsert,
	//		blkDefId);
	//	// ���������ӵ�ģ�Ϳռ�
	//	AcDbBlockTableRecord *pBlkTblRcd;
	//	pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRcd,
	//		AcDb::kForWrite);
	//	AcDbObjectId entId;
	//	pBlkTblRcd->appendAcDbEntity(entId, pBlkRef);
	//	// �ر����ݿ�Ķ���
	//	pBlkRef->close();
	//	pBlkTblRcd->close();
	//	pBlkTbl->close();

	//	acutPrintf(L"\n��ɲ���飡");
	//}

	static void MyGroupMyInsert()
	{
		//���Ҫ����Ŀ���
		CString blockname;
		//m_listctrl.GetLBText(m_listctrl.GetCurSel(), blockname);

		//blockname = "CHART-20";

		//Ѱ���Ƿ��Ѿ�����
		AcDbDatabase *pCurDb = acdbHostApplicationServices()->workingDatabase();
		AcDbBlockTable *pBlkTable;
		AcDbObjectId blockId;
		pCurDb->getBlockTable(pBlkTable, AcDb::kForRead);

		if (!pBlkTable->has(blockname))
		{
			pBlkTable->close();
			AcDbDatabase *pDwg = new AcDbDatabase(Adesk::kFalse);
			//char dir[MAX_PATH];
			//GetModuleFileName(NULL, dir, MAX_PATH);

			//dir[CString(dir).ReverseFind('\')]='\0';
				//AfxMessageBox(CString(dir)+"\\survingpack\"+blockname+".dwg");
				pDwg->readDwgFile(L"D:\\5.dwg") ;

					Acad::ErrorStatus es = pCurDb->insert(blockId, blockname, pDwg);//, Adesk::kFalse) ; //
			delete pDwg;
			if (es != Acad::eOk)
			{
				acutPrintf(L"\n��������.");
				return;
			}
		}

		else
			pBlkTable->getAt(blockname, blockId);


		//BeginEditorCommand();
		//ShowWindow(SW_HIDE);
		ads_point pt = { 0,0,0 };
		int rc = acedGetPoint(NULL,L"\nѡ������:", pt);
		if (rc == RTCAN || rc == RTNONE)
		{
			acutPrintf(L"\n*ȡ���˲������*");
			//CancelEditorCommand();
			return;
		}
		//CompleteEditorCommand();

		//---- ���ò���㣬��ת�Ƕȣ������ȵ�
		AcDbBlockReference *pBlkRef = new AcDbBlockReference(AcGePoint3d(pt[0], pt[1], pt[2]), blockId);
		//pBlkRef->setBlockTableRecord (blockId) ;
		pBlkRef->setScaleFactors(AcGeScale3d(2, 1.5, 1));
		//pBlkRef->setPosition(AcGePoint3d(pt[0],pt[1],pt[2])) ;
		pBlkRef->setRotation(0);
		pBlkRef->setLayer(NULL); //����ͼ��



								 //���ģ�Ϳռ����¼
		AcDbBlockTable *pBlockTable;
		acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead);
		AcDbBlockTableRecord *pBlockTableRecord;
		pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
		pBlockTable->close();
		pBlockTableRecord->appendAcDbEntity(pBlkRef);

		//�������
		AcDbBlockTableRecord *pBlkDefRecord;
		acdbOpenObject(pBlkDefRecord, blockId, AcDb::kForRead);

		//if (pBlkDefRecord->hasAttributeDefinitions())
		//{
		//	//AcDbObjectIterator* pBlkIterator = pBlkRef->attributeIterator(); //�޸�

		//	AcDbBlockTableRecordIterator *pIterator;
		//	pBlkDefRecord->newIterator(pIterator);

		//	for (pIterator->start(); !pIterator->done(); pIterator->step())
		//	{
		//		AcDbEntity *pEnt;
		//		pIterator->getEntity(pEnt, AcDb::kForRead);
		//		AcDbAttributeDefinition *pAttDef = AcDbAttributeDefinition::cast(pEnt);

		//		if (pAttDef != NULL && !pAttDef->isConstant())
		//		{
		//			AcDbAttribute* pAtt = new AcDbAttribute();
		//			pAtt->setPropertiesFrom(pAttDef);
		//			pAtt->setInvisible(pAttDef->isInvisible());

		//			pAtt->setHorizontalMode(pAttDef->horizontalMode());
		//			pAtt->setVerticalMode(pAttDef->verticalMode());

		//			AcGePoint3d basePt = pAttDef->alignmentPoint();
		//			basePt[0] += pt[0];
		//			basePt[1] += pt[1];
		//			basePt[2] += pt[2];
		//			pAtt->setAlignmentPoint(basePt);

		//			pAtt->setHeight(pAttDef->height());
		//			pAtt->setTextStyle(pAttDef->textStyle());

		//			pAtt->setTag(pAttDef->tag());
		//			pAtt->setTextString(m_attrib);
		//			pAtt->setFieldLength(25);

		//			pBlkRef->appendAttribute(pAtt);
		//			pAtt->close();
		//			pEnt->close();
		//		}
		//	}
		//	delete pIterator;
		//}//end if pBlkDefRecord->hasAttributeDefinitions

		pBlkDefRecord->close();
		pBlockTableRecord->close();
		pBlkRef->close();
	}

	static void Move(AcDbObjectId entId, AcGePoint3d ptBase,AcGePoint3d ptDest)
	{
		// ���ñ任����Ĳ���
		AcGeMatrix3d xform;
		AcGeVector3d vec(ptDest.x - ptBase.x, ptDest.y - ptBase.y,
			ptDest.z - ptBase.z);
		xform.setToTranslation(vec);
		AcDbEntity *pEnt;
		Acad::ErrorStatus es = acdbOpenObject(pEnt, entId, AcDb::kForWrite,
			false);
		pEnt->transformBy(xform);
		pEnt->close();

	}

	static void MyGroupMySave()

	{

		AcDbDatabase* pDb = new AcDbDatabase(Adesk::kFalse);

		Acad::ErrorStatus es = pDb->readDwgFile(L"d:\\2.dwg"); //AcApDocument* pDoc = acDocManager->curDocument();//testing

		//assert(es == Acad::eOk);


		//// get the block table

		//AcDbBlockTable *pBlockTable;

		//es = pDb->getBlockTable(pBlockTable,

		//	AcDb::kForRead);

		//if (es != Acad::eOk)

		//{

		//	return;

		//}

		//// get model space

		//AcDbBlockTableRecord *pBlockTableRec;

		//es = pBlockTable->

		//	getAt(ACDB_MODEL_SPACE, pBlockTableRec,

		//		AcDb::kForWrite);

		//3 T(n) d0 F4 \: {*F
		//	if (es != Acad::eOk)

		//	{

		//		pBlockTable->close();

		//		return;

		//	}


		//pBlockTable->close();

		//// create a new entity7 L  ~& l# C- C( D% u% h+ w
		//AcDbCircle *pCircle =

		//	new AcDbCircle(AcGePoint3d(0, 0, 0),

		//		AcGeVector3d(0, 0, 1), 100);


		//// add the new entity to the model space

		//AcDbObjectId objId;

		//pBlockTableRec->appendAcDbEntity(objId, pCircle);

		//1 w, x / o4 S7 X, W
		//	// close the entity

		//	pCircle->close();

		//// close the model space block

		//pBlockTableRec->close();


		// save as to the new drawing

		es = pDb->saveAs(L"d:\\3.dwg");

		assert(es == Acad::eOk);

		delete pDb;

		}
	
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CArxProject2App)

ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, MyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, MyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, MyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION, NULL)
ACED_ADSSYMBOL_ENTRY_AUTO(CArxProject2App, MyLispFunction, false)

ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, MyGroup, MyCommand1, MM, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, MyGroup, MySave, MS, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, MyGroup, MyInsert, MIn, ACRX_CMD_MODAL, NULL)