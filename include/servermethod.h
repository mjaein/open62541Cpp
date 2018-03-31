/*
 * Copyright (C) 2017 -  B. J. Hill
 *
 * This file is part of open62541 C++ classes. open62541 C++ classes are free software: you can
 * redistribute it and/or modify it under the terms of the Mozilla Public
 * License v2.0 as stated in the LICENSE file provided with open62541.
 *
 * open62541 C++ classes are distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.
 */
#ifndef SERVERMETHOD_H
#define SERVERMETHOD_H
#include <open62541objects.h>

#include <nodecontext.h>
namespace Open62541
{

/*!
    \brief The ServerMethod class
*/
class  UA_EXPORT  ServerMethod  : public NodeContext {

        const std::string _name;
        ArgumentList  _in;
        ArgumentList  _out;
        /*!
            \brief methodCallback
            \param handle
            \param objectId
            \param inputSize
            \param input
            \param outputSize
            \param output
            \return
        */
public:
        static UA_StatusCode
        methodCallback(UA_Server *server, const UA_NodeId *sessionId,
                             void *sessionContext, const UA_NodeId *methodId,
                             void *methodContext, const UA_NodeId *objectId,
                             void *objectContext, size_t inputSize,
                             const UA_Variant *input, size_t outputSize,
                             UA_Variant *output);

    protected:
        UA_StatusCode _lastError;

    public:
        /*!
            \brief ServerMethod
            \param s
            \param n
            \param nInputs
            \param nOutputs
        */
        ServerMethod(const std::string &n,
                     int nInputs = 1,
                     int nOutputs = 1);

        virtual ~ServerMethod() {}

        /*!
            \brief in
            \return
        */
        ArgumentList   &in() {
            return _in;
        }
        /*!
            \brief out
            \return
        */
        ArgumentList   &out() {
            return _out;
        }


        /*!
            \brief callback
            \return
        */
        virtual UA_StatusCode callback(Server &/*server*/,
                                       const UA_NodeId */*objectId*/,
                                       size_t /*inputSize*/,
                                       const UA_Variant * /*input*/,
                                       size_t /*outputSize*/,
                                       UA_Variant * /*output*/) {

            return UA_STATUSCODE_GOOD;
        }
        /*!
            \brief lastOK
            \return
        */
        bool lastOK() {
            return _lastError == UA_STATUSCODE_GOOD;
        }

        /*!
         * \brief setMethodNodeCallBack
         * \param s
         * \param node
         * \return
         */
        bool setMethodNodeCallBack(Open62541::Server &s, Open62541::NodeId &node);

        /*!
         * \brief addServerMethod
         * \param browseName
         * \param parent
         * \param nodeId
         * \param newNode
         * \param nameSpaceIndex
         * \return
         */
        bool addServerMethod(Open62541::Server &s, const std::string &browseName,
                             Open62541::NodeId &parent,  Open62541::NodeId &nodeId,
                             Open62541::NodeId &newNode = NodeId::Null,  int nameSpaceIndex = 0);
};

/*!
    \brief ServerMethodRef
*/
typedef std::shared_ptr<ServerMethod> ServerMethodRef;
}
#endif // SERVERMETHOD_H
