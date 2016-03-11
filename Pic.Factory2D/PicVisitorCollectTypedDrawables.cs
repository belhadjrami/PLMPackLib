#region Using directives
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
#endregion

namespace Pic.Factory2D
{
    public class PicVisitorCollectTypedDrawables : PicFactoryVisitor, IDisposable
    {
        #region Constructor
        public PicVisitorCollectTypedDrawables()
        { 
        }
        #endregion

        #region IDisposable
        public void Dispose()
        { 
        }
        #endregion

        #region Overrides PicFactoryVisitor
        public override void Initialize(PicFactory factory)
        {
            _entities.Clear();
        }
        public override void ProcessEntity(PicEntity entity)
        {
            PicTypedDrawable drawable = entity as PicTypedDrawable;
            if (null != drawable)
                _entities.Add(drawable);
        }
        public override void Finish()
        {
        }
        #endregion

        #region Public properties
        public List<PicTypedDrawable> Entities
        {
            get { return _entities; } 
        }
        #endregion

        #region Data members
        private List<PicTypedDrawable> _entities = new List<PicTypedDrawable>();
        #endregion
    }
}
