CREATE TABLE benefits (
    name character varying(255) NOT NULL,
    sum double precision NOT NULL
);

CREATE TABLE benefits_tenants (
    tenant_name character varying(255) NOT NULL,
    benefit_name character varying(255) NOT NULL
);

CREATE TABLE flats (
    number integer NOT NULL,
    address character varying(255) NOT NULL,
    square double precision NOT NULL,
    entrance_number integer NOT NULL,
    rent_sum double precision NOT NULL
);

CREATE TABLE houses (
    address character varying(255) NOT NULL,
    number character varying(255) NOT NULL
);

CREATE TABLE tenants (
    name character varying(255) NOT NULL,
    address character varying(255) NOT NULL,
    flat_number integer NOT NULL,
    sex character(2044) NOT NULL,
    age integer NOT NULL
);

ALTER TABLE ONLY benefits
    ADD CONSTRAINT benefits_pkey PRIMARY KEY (name);

ALTER TABLE ONLY benefits_tenants
    ADD CONSTRAINT benefits_tenants_pkey PRIMARY KEY (benefit_name, tenant_name);

ALTER TABLE ONLY flats
    ADD CONSTRAINT flats_pkey PRIMARY KEY (number, address);

ALTER TABLE ONLY houses
    ADD CONSTRAINT houses_pkey PRIMARY KEY (address);

ALTER TABLE ONLY tenants
    ADD CONSTRAINT tenants_pkey PRIMARY KEY (name);

ALTER TABLE ONLY benefits_tenants
    ADD CONSTRAINT lnk_benefits_tenants_benefits FOREIGN KEY (benefit_name) REFERENCES benefits(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY benefits_tenants
    ADD CONSTRAINT lnk_benefits_tenants_tenants FOREIGN KEY (tenant_name) REFERENCES tenants(name) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY flats
    ADD CONSTRAINT lnk_flats_houses FOREIGN KEY (address) REFERENCES houses(address) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE ONLY tenants
    ADD CONSTRAINT lnk_tenants_flats FOREIGN KEY (flat_number, address) REFERENCES flats(number, address) MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;

