--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: achivements; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE achivements (
    name character varying(255) NOT NULL,
    description character varying(1024) NOT NULL,
    topicality boolean NOT NULL,
    date date NOT NULL
);


ALTER TABLE public.achivements OWNER TO postgres;

--
-- Name: achivements_teachers; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE achivements_teachers (
    achivement_name character varying(255) NOT NULL,
    teacher_name character varying(255) NOT NULL
);


ALTER TABLE public.achivements_teachers OWNER TO postgres;

--
-- Name: authorships; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE authorships (
    publication_name character varying(255) NOT NULL,
    teacher_name character varying(255) NOT NULL
);


ALTER TABLE public.authorships OWNER TO postgres;

--
-- Name: confereces_teachers; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE confereces_teachers (
    conference_date date NOT NULL,
    teacher_name character varying(255) NOT NULL,
    conference_theme character varying(255) NOT NULL
);


ALTER TABLE public.confereces_teachers OWNER TO postgres;

--
-- Name: conferences; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE conferences (
    date date NOT NULL,
    theme character varying(255) NOT NULL,
    place character varying(255) NOT NULL,
    type character varying(255) NOT NULL
);


ALTER TABLE public.conferences OWNER TO postgres;

--
-- Name: disciplines; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE disciplines (
    name character varying(255) NOT NULL,
    hours integer NOT NULL,
    id integer NOT NULL
);


ALTER TABLE public.disciplines OWNER TO postgres;

--
-- Name: disciplines_teachers; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE disciplines_teachers (
    teacher_name character varying(255) NOT NULL,
    discipline_id integer NOT NULL
);


ALTER TABLE public.disciplines_teachers OWNER TO postgres;

--
-- Name: publications; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE publications (
    name character varying(255) NOT NULL,
    house character varying(255) NOT NULL,
    circulation character varying(255) NOT NULL,
    date date NOT NULL,
    page_count integer NOT NULL
);


ALTER TABLE public.publications OWNER TO postgres;

--
-- Name: scientific_managements; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE scientific_managements (
    student_name character varying(255) NOT NULL,
    teacher_name character varying(255) NOT NULL,
    theme character varying(255) NOT NULL,
    type character varying(2044) NOT NULL
);


ALTER TABLE public.scientific_managements OWNER TO postgres;

--
-- Name: teachers; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE teachers (
    name character varying(255) NOT NULL,
    title character varying(255) NOT NULL,
    post character varying(255) NOT NULL
);


ALTER TABLE public.teachers OWNER TO postgres;

--
-- Data for Name: achivements; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY achivements (name, description, topicality, date) FROM stdin;
\.


--
-- Data for Name: achivements_teachers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY achivements_teachers (achivement_name, teacher_name) FROM stdin;
\.


--
-- Data for Name: authorships; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY authorships (publication_name, teacher_name) FROM stdin;
\.


--
-- Data for Name: confereces_teachers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY confereces_teachers (conference_date, teacher_name, conference_theme) FROM stdin;
\.


--
-- Data for Name: conferences; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY conferences (date, theme, place, type) FROM stdin;
\.


--
-- Data for Name: disciplines; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY disciplines (name, hours, id) FROM stdin;
\.


--
-- Data for Name: disciplines_teachers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY disciplines_teachers (teacher_name, discipline_id) FROM stdin;
\.


--
-- Data for Name: publications; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY publications (name, house, circulation, date, page_count) FROM stdin;
\.


--
-- Data for Name: scientific_managements; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY scientific_managements (student_name, teacher_name, theme, type) FROM stdin;
\.


--
-- Data for Name: teachers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY teachers (name, title, post) FROM stdin;
Федо	тетс	тест
\.


--
-- Name: achivements_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY achivements
    ADD CONSTRAINT achivements_pkey PRIMARY KEY (name);


--
-- Name: achivements_teachers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY achivements_teachers
    ADD CONSTRAINT achivements_teachers_pkey PRIMARY KEY (achivement_name, teacher_name);


--
-- Name: authorship_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY authorships
    ADD CONSTRAINT authorship_pkey PRIMARY KEY (publication_name, teacher_name);


--
-- Name: confereces_teachers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT confereces_teachers_pkey PRIMARY KEY (conference_date, conference_theme, teacher_name);


--
-- Name: conferences_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY conferences
    ADD CONSTRAINT conferences_pkey PRIMARY KEY (date, theme);


--
-- Name: disciplines_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY disciplines
    ADD CONSTRAINT disciplines_pkey PRIMARY KEY (id);


--
-- Name: disciplines_teachers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT disciplines_teachers_pkey PRIMARY KEY (discipline_id, teacher_name);


--
-- Name: publications_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY publications
    ADD CONSTRAINT publications_pkey PRIMARY KEY (name, date);


--
-- Name: scientific_managements_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY scientific_managements
    ADD CONSTRAINT scientific_managements_pkey PRIMARY KEY (student_name, teacher_name);


--
-- Name: teachers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY teachers
    ADD CONSTRAINT teachers_pkey PRIMARY KEY (name);


--
-- Name: unique_conference_date; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT unique_conference_date UNIQUE (conference_date);


--
-- Name: unique_conference_theme; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT unique_conference_theme UNIQUE (conference_theme);


--
-- Name: unique_discipline_id; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT unique_discipline_id UNIQUE (discipline_id);


--
-- Name: unique_name; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY publications
    ADD CONSTRAINT unique_name UNIQUE (name);


--
-- Name: unique_teacher_name; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT unique_teacher_name UNIQUE (teacher_name);


--
-- Name: lnk_achivements_teachers_achivements; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY achivements_teachers
    ADD CONSTRAINT lnk_achivements_teachers_achivements FOREIGN KEY (achivement_name) REFERENCES achivements(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: lnk_achivements_teachers_teachers; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY achivements_teachers
    ADD CONSTRAINT lnk_achivements_teachers_teachers FOREIGN KEY (teacher_name) REFERENCES teachers(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: lnk_authorship_publications; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY authorships
    ADD CONSTRAINT lnk_authorship_publications FOREIGN KEY (publication_name) REFERENCES publications(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: lnk_authorship_teachers; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY authorships
    ADD CONSTRAINT lnk_authorship_teachers FOREIGN KEY (teacher_name) REFERENCES teachers(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: lnk_confereces_teachers_conferences; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT lnk_confereces_teachers_conferences FOREIGN KEY (conference_date, conference_theme) REFERENCES conferences(date, theme) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: lnk_confereces_teachers_teachers; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT lnk_confereces_teachers_teachers FOREIGN KEY (teacher_name) REFERENCES teachers(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: lnk_disciplines_teachers_disciplines2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT lnk_disciplines_teachers_disciplines2 FOREIGN KEY (discipline_id) REFERENCES disciplines(id) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: lnk_disciplines_teachers_teachers2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT lnk_disciplines_teachers_teachers2 FOREIGN KEY (teacher_name) REFERENCES teachers(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: public; Type: ACL; Schema: -; Owner: mihailpospelov
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM mihailpospelov;
GRANT ALL ON SCHEMA public TO mihailpospelov;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- PostgreSQL database dump complete
--

