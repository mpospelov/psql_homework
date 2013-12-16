CREATE TABLE achivements (
    name character varying(255) NOT NULL,
    description character varying(1024) NOT NULL,
    topicality boolean NOT NULL,
    date date NOT NULL
);

CREATE TABLE achivements_teachers (
    achivement_name character varying(255) NOT NULL,
    teacher_name character varying(255) NOT NULL
);

CREATE TABLE authorships (
    publication_name character varying(255) NOT NULL,
    teacher_name character varying(255) NOT NULL
);


CREATE TABLE confereces_teachers (
    conference_date date NOT NULL,
    teacher_name character varying(255) NOT NULL,
    conference_theme character varying(255) NOT NULL
);


CREATE TABLE conferences (
    date date NOT NULL,
    theme character varying(255) NOT NULL,
    place character varying(255) NOT NULL,
    type character varying(255) NOT NULL
);



CREATE TABLE disciplines (
    name character varying(255) NOT NULL,
    hours integer NOT NULL,
    id integer NOT NULL
);


CREATE TABLE disciplines_teachers (
    teacher_name character varying(255) NOT NULL,
    discipline_id integer NOT NULL
);

CREATE TABLE publications (
    name character varying(255) NOT NULL,
    house character varying(255) NOT NULL,
    circulation character varying(255) NOT NULL,
    date date NOT NULL,
    page_count integer NOT NULL
);

CREATE TABLE scientific_managements (
    student_name character varying(255) NOT NULL,
    teacher_name character varying(255) NOT NULL,
    theme character varying(255) NOT NULL,
    type character varying(2044) NOT NULL
);

CREATE TABLE teachers (
    name character varying(255) NOT NULL,
    title character varying(255) NOT NULL,
    post character varying(255) NOT NULL
);

ALTER TABLE ONLY achivements
    ADD CONSTRAINT achivements_pkey PRIMARY KEY (name);

ALTER TABLE ONLY achivements_teachers
    ADD CONSTRAINT achivements_teachers_pkey PRIMARY KEY (achivement_name, teacher_name);

ALTER TABLE ONLY authorships
    ADD CONSTRAINT authorship_pkey PRIMARY KEY (publication_name, teacher_name);

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT confereces_teachers_pkey PRIMARY KEY (conference_date, conference_theme, teacher_name);


ALTER TABLE ONLY conferences
    ADD CONSTRAINT conferences_pkey PRIMARY KEY (date, theme);

ALTER TABLE ONLY disciplines
    ADD CONSTRAINT disciplines_pkey PRIMARY KEY (id);


ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT disciplines_teachers_pkey PRIMARY KEY (discipline_id, teacher_name);

ALTER TABLE ONLY publications
    ADD CONSTRAINT publications_pkey PRIMARY KEY (name, date);

ALTER TABLE ONLY scientific_managements
    ADD CONSTRAINT scientific_managements_pkey PRIMARY KEY (student_name, teacher_name);

ALTER TABLE ONLY teachers
    ADD CONSTRAINT teachers_pkey PRIMARY KEY (name);

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT unique_conference_date UNIQUE (conference_date);

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT unique_conference_theme UNIQUE (conference_theme);

ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT unique_discipline_id UNIQUE (discipline_id);

ALTER TABLE ONLY publications
    ADD CONSTRAINT unique_name UNIQUE (name);

ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT unique_teacher_name UNIQUE (teacher_name);

ALTER TABLE ONLY achivements_teachers
    ADD CONSTRAINT lnk_achivements_teachers_achivements FOREIGN KEY (achivement_name) REFERENCES achivements(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY achivements_teachers
    ADD CONSTRAINT lnk_achivements_teachers_teachers FOREIGN KEY (teacher_name) REFERENCES teachers(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY authorships
    ADD CONSTRAINT lnk_authorship_publications FOREIGN KEY (publication_name) REFERENCES publications(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY authorships
    ADD CONSTRAINT lnk_authorship_teachers FOREIGN KEY (teacher_name) REFERENCES teachers(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT lnk_confereces_teachers_conferences FOREIGN KEY (conference_date, conference_theme) REFERENCES conferences(date, theme) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY confereces_teachers
    ADD CONSTRAINT lnk_confereces_teachers_teachers FOREIGN KEY (teacher_name) REFERENCES teachers(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT lnk_disciplines_teachers_disciplines2 FOREIGN KEY (discipline_id) REFERENCES disciplines(id) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY disciplines_teachers
    ADD CONSTRAINT lnk_disciplines_teachers_teachers2 FOREIGN KEY (teacher_name) REFERENCES teachers(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;
