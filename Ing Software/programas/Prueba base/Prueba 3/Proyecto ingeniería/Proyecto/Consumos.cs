using System;
using System.Collections.Generic;
using System.Text;

namespace Proyecto
{
    public class Consumos
    {
        private string nombre;
        private int claveUnica;
        private string claveConsumo;
        private decimal precio;
        private DateTime fechaEmision;
        public Consumos() { }
        public Consumos(string nombre, int claveUnica, string claveConsumo, decimal precio)
        {
            this.nombre = nombre;
            this.claveUnica = claveUnica;
            this.claveConsumo = claveConsumo;
            this.precio = precio;
            fechaEmision = DateTime.Now;
        }
        public string Nombre
        {
            get { return nombre; }
        }
        public int ClaveUnica
        {
            get { return claveUnica; }
        }
        public string ClaveConsumo
        {
            get { return claveConsumo; }
        }
        public decimal Precio
        {
            get { return precio; }
        }
        public DateTime FechaEmision
        {
            get { return fechaEmision; }
        }
        public override string ToString()
        {
            return string.Format($"\nNombre consumo: {nombre}\nClave Unica: {claveUnica}\nClave Unica: {claveConsumo}\nPrecio consumo: {precio}\nFecha Emision Consumo: {fechaEmision}");
        }
    }
}
