/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of PlantUML.
 *
 * PlantUML is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PlantUML distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 *
 * Original Author:  Arnaud Roques
 *
 *
 *
 *
 *************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************
 *
 */
package h;
import smetana.core.*;
import java.util.Arrays;
import java.util.List;

//2 8p2u7sziyialmpuyrxsg8ptw6

public interface lexstate_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct",
"{",
"char* ptr",
"int tok",
"agxbuf* xb",
"agxbuf  lb",
"char warn",
"char error",
"char inCell",
"char mode",
"char *currtok",
"char *prevtok",
"int currtoklen",
"int prevtoklen",
"}",
"lexstate_t");
}

// typedef struct {
// 
//     
// 
//     char* ptr;			/* input source */
//     int tok;			/* token type   */
//     agxbuf* xb;			/* buffer to gather T_string data */
//     agxbuf  lb;			/* buffer for translating lexical data */
//     char warn;			/* set if warning given */
//     char error;			/* set if error given */
//     char inCell;		/* set if in TD to allow T_string */
//     char mode;			/* for handling artificial <HTML>..</HTML> */
//     char *currtok;		/* for error reporting */
//     char *prevtok;		/* for error reporting */
//     int currtoklen;
//     int prevtoklen;
// } lexstate_t;